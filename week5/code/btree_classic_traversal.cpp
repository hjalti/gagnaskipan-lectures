#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* NodePtr;

NodePtr parse_tree()
{
    char c;
    cin >> c; // Read (

    cin >> c; // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')')
    {
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
    if(tree == NULL)
    {
        return;
    }
    print_infix(tree->left);
    cout << tree->data << " ";
    print_infix(tree->right);

}

void print_postfix(NodePtr tree)
{
    if(tree == NULL)
    {
        return;
    }
    print_postfix(tree->left);
    print_postfix(tree->right);
    cout << tree->data << " ";

}

void print_prefix(NodePtr tree)
{
    if(tree == NULL)
    {
        return;
    }
    cout << tree->data << " ";
    print_prefix(tree->left);
    print_prefix(tree->right);

}

int main()
{
    NodePtr tree = parse_tree();
    print_infix(tree);
    cout << endl;
    return 0;
}
