#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

struct TreeNode
{
    TreeNode(int data, TreeNode *left = NULL, TreeNode *right = NULL)
        : data(data), left(left), right(right) { }

    int data;
    TreeNode *left;
    TreeNode *right;
};

typedef TreeNode* NodePtr;

class IntSet
{
    public:
        // Contstructs a new set
        IntSet();

        ~IntSet();

        // Returns the number of (distinct) elements in the set.
        int size();

        bool empty();

        // Returns true if and only if the set contains 'item'.
        bool contains(int item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        void insert(int item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        void remove(int item);

        // Returns the smallest element of the set.
        // Returns INT_MIN if set is empty.
        int min();

        void print_graphviz();

        friend ostream& operator<< (ostream& outs, IntSet set);

    private:
        NodePtr root;

        int size(NodePtr node);
        int min(NodePtr node);
        void clear(NodePtr node);
        bool contains(NodePtr node, int item);
        void insert(NodePtr& node, int item);
        void print_inorder(ostream& outs,  NodePtr& node);
        void print_graphviz(NodePtr node);
};

IntSet::IntSet() {
    root = NULL;
}

IntSet::~IntSet() {
    clear(root);
}

void IntSet::clear(NodePtr node) {
    if(node != NULL) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int IntSet::size() {
    return size(root);
}

int IntSet::size(NodePtr node) {
    if(node == NULL) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

bool IntSet::empty() {
    return root == NULL;
}


bool IntSet::contains(int item) {
    return contains(root, item);
}

int IntSet::min() {
    return min(root);
}

int IntSet::min(NodePtr node) {
    if(node== NULL) {
        return INT_MIN;
    }
    if(node->left == NULL) {
        return node->data;
    }
    return min(node->left);
}

bool IntSet::contains(NodePtr node, int item) {
    if(node == NULL) {
        return false;
    }
    if(node->data == item) {
        return true;
    }
    if(item < node->data) {
        return contains(node->left, item);
    }
    return contains(node->right, item);

}

void IntSet::insert(int item) {
    insert(root, item);
}

void IntSet::insert(NodePtr& node, int item) {
    if(node == NULL) {
        node = new TreeNode(item);
    } else if(item < node->data) {
        insert(node->left, item);
    } else if(item > node->data) {
        insert(node->right, item);
    }
}

void IntSet::remove(int item) {
    //TODO
}

void IntSet::print_inorder(ostream& outs, NodePtr& node) {
    if(node != NULL) {
        print_inorder(outs, node->left);
        outs << node->data << " ";
        print_inorder(outs, node->right);
    }
}

void IntSet::print_graphviz() {
    cout << "digraph G {" << endl;
    print_graphviz(root);
    cout << "}" << endl;
}

void IntSet::print_graphviz(NodePtr node) {
    if(node != NULL) {
        if(node->left != NULL) {
            cout << node->data << " -> " << node->left->data << ";" << endl;
        }
        if(node->right != NULL) {
            cout << node->data << " -> " << node->right->data << ";" << endl;
        }
        print_graphviz(node->left);
        print_graphviz(node->right);
    }
}

ostream& operator<< (ostream& outs, IntSet set) {
    set.print_inorder(outs, set.root);
    return outs;
}


int main() {
    srand(1337);

    IntSet s;

    for(int i = 0; i != 1000000; i++) {
        s.insert(rand() % 100000);
    }

    s.print_graphviz();
}
