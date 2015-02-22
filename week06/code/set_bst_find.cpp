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

        friend ostream& operator<< (ostream& outs, const IntSet& set);

    private:
        NodePtr root;

        int size(NodePtr node);
        NodePtr& min(NodePtr& node);
        void clear(NodePtr node);
        void print_inorder(ostream& outs, NodePtr node) const;
        NodePtr& find(NodePtr& node, int item);
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

NodePtr& IntSet::find(NodePtr& node, int item) {
    if(node == NULL) {
        return node;
    } else if(item < node->data) {
        return find(node->left, item);
    } else if(item > node->data) {
        return find(node->right, item);
    }
    return node;
}

bool IntSet::contains(int item) {
    return find(root, item) != NULL;
}

void IntSet::insert(int item) {
    NodePtr& ins = find(root, item);
    if(ins == NULL) {
        ins = new TreeNode(item);
    }
}

void IntSet::remove(int item) {
    NodePtr& rem = find(root, item);
    if(rem == NULL) {
        return;
    } else {
        NodePtr to_del = rem;
        if(rem->left == NULL) {
            rem = rem->right;
        } else if (rem->right == NULL) {
            rem = rem->left;
        } else {
            NodePtr& leftmost = min(rem->right);
            to_del = leftmost;
            rem->data = leftmost->data;
            leftmost = leftmost->right;
        }
        delete to_del;
    }
}

NodePtr& IntSet::min(NodePtr& node) {
    if(node == NULL || node->left == NULL) {
        return node;
    }
    return min(node->left);
}

void IntSet::print_inorder(ostream& outs, NodePtr node) const {
    if(node != NULL) {
        print_inorder(outs, node->left);
        outs << node->data << " ";
        print_inorder(outs, node->right);
    }
}

ostream& operator<< (ostream& outs, const IntSet& set) {
    set.print_inorder(outs, set.root);
    return outs;
}

int main() {
    srand(137872);

    IntSet s;
    for(int i = 0; i != 20; i++) {
        s.insert(rand() % 30);
    }

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s.contains(i) ? "Yes" : "No") << endl;
        if (i % 2 == 0) {
            s.remove(i);
        }
    }
    cout << endl;

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s.contains(i) ? "Yes" : "No") << endl;
    }

    clock_t start = clock();

    for(int i = 0; i != 1000000; i++) {
        s.insert(rand() % 100000);
    }

    cout << "Done inserting" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;

    cout << "Querying" << endl;

    start = clock();

    for(int i = 0; i != 1000000; i++) {
        s.contains(i);
    }

    cout << "Done querying" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;
}
