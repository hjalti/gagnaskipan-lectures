#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    bool is_leaf();
};

bool TreeNode::is_leaf()
{
    return (left == NULL && right == NULL);
}

typedef TreeNode* NodePtr;

NodePtr parse_tree()
{
    char c;
    cin >> c; // Read (

    cin >> c; // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')') {
        return NULL;
    }

    // Return the "borrowed" character to the input stream
    cin.putback(c);

    int node_data;
    cin >> node_data;

    NodePtr node = new TreeNode;
    node->data = node_data;
    node->left = parse_tree();
    node->right = parse_tree();

    cin >> c; // Consume the trailing )

    return node;
}

void print_infix(NodePtr tree)
{
    if(tree == NULL) {
        return;
    }
    print_infix(tree->left);
    cout << tree->data << " ";
    print_infix(tree->right);

}

void print_postfix(NodePtr tree)
{
    if(tree == NULL) {
        return;
    }
    print_infix(tree->left);
    print_infix(tree->right);
    cout << tree->data << " ";

}

void print_prefix(NodePtr tree)
{
    if(tree == NULL) {
        return;
    }
    cout << tree->data << " ";
    print_infix(tree->left);
    print_infix(tree->right);

}

const int INDENT_SIZE = 3;

void indent(int level)
{
    for(int i = 0; i != level * INDENT_SIZE; i++) {
        cout << " ";
    }
}

void print_tree(NodePtr tree, int level = 0)
{
    indent(level);
    if(tree == NULL) {
        cout << "()" << endl;
        return;
    }
    cout << "(" << tree->data << endl;
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
    indent(level);
    cout << ")" << endl;
}

// Prints the end symbol of a lisp-style representation of a tree. If the tree
// is not a rightmost child, the end symbol is a newline character. Otherwise,
// there is no end symbol (i.e., it is the empty string).
void tree_end(bool right)
{
    if(!right) {
        cout << endl;
    }
}

// Print tree lisp-style
void print_tree_lisp(NodePtr tree, int level = 0, bool right = false)
{
    indent(level);
    if(tree == NULL) {
        cout << "()";
        tree_end(right);
        return;
    }
    // Print leaves as numbers inside brackets, but not
    // with two empty children.
    cout << "(" << tree->data;
    if(tree->is_leaf()) {
        cout << ")";
        tree_end(right);
    } else {
        cout << endl;
        print_tree_lisp(tree->left, level + 1, false);
        print_tree_lisp(tree->right, level + 1, true);
        cout << ")";
        tree_end(right);
    }
}

int main()
{
    NodePtr tree = parse_tree();
    print_tree_lisp(tree);
    cout << endl;
    return 0;
}
