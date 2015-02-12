#include <iostream>
#include <cassert>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* NodePtr;

NodePtr parse_tree() {
    char c;
    assert(cin >> c && c == '('); // Read (

    assert(cin >> c); // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')')
    {
        return NULL;
    }

    // Return the "borrowed" character to the input stream
    cin.putback(c);

    int node_data;
    assert(cin >> node_data);

    NodePtr node = new TreeNode;
    node->data = node_data;
    node->left = parse_tree();
    node->right = parse_tree();

    assert(cin >> c && c == ')'); // Consume the trailing )

    return node;
}

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void print_infix();
        void read_tree();
        int size();
    private:
        void print_infix(NodePtr node);
        void clear(NodePtr node);
        int size(NodePtr node);

        NodePtr root;
};

void BinaryTree::print_infix(NodePtr tree)
{
    if(tree != NULL) {
        print_infix(tree->left);
        cout << tree->data << " ";
        print_infix(tree->right);
    }
}

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    clear(root);
}

int BinaryTree::size(NodePtr node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

int BinaryTree::size() {
    return size(root);
}

void BinaryTree::clear(NodePtr node) {
    if (node != NULL) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BinaryTree::print_infix() {
    print_infix(root);
}

void BinaryTree::read_tree() {
    root = parse_tree();
}

int main()
{
    BinaryTree t;
    t.read_tree();

    t.print_infix();
    cout << endl;
    cout << t.size() << endl;

    return 0;
}
