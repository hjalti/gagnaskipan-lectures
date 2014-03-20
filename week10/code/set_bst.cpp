#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <climits>

class KeyException { };

template<class T>
class Map {

    public:
        // Creates an empty map.
        StringContactMap ();

        ~StringContactMap();

        // Returns the number ef entries in this map.
        int size() const;

        // Returns true if and only if the map contains no entries.
        bool empty() const;

        // Returns a vector containing the contacts in this map, ordered by
        // their keys in increasing order.
        vector<Contact> all_contacts() const;

        // Adds the specified key to the map associated with the specified
        // contact.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(string key, Contact value);

        // Returns true if and only if there exists an entry in the map with
        // the specified key.
        bool contains(string key) const;

        // Returns the contact associated wih the specified key.
        // Throws KeyException if no such contact exists.
        Contact get(string key) const;

        // Removes the entry with the specified key from the map.
        // If no entry in the map has the specified key, this operation has no
        // effect.
        void remove(string key);

        // Returns a vector containing the contacts in this map, whose key is
        // prefixed by 'prefix'. The contacts are ordered by their
        // keys in increasing order,
        vector<Contact> prefix_search(string prefix) const;

        friend ostream& operator <<(ostream& out, const StringContactMap& map);

    private:
        NodePtr root;

        // Deallocates all memory allocated for the specified tree.
        void free_memory(NodePtr node);

        int size(NodePtr node) const;

        // Adds the specified key, to the specified tree, associated with the
        // specified contact.
        // If there exists an entry in the tree with the specified key, it
        // should be replaced.
        // Note: This is an optional helper function
        void add(NodePtr& node, string key, Contact value);

        // Returns true if and only if there exists an entry in the map with
        // the specified key in the specified tree.
        // Note: This is an optional helper function
        bool contains(NodePtr node, string key) const;

        // Returns the contact associated wih the specified key in the
        // specified tree.
        // Throws KeyException if no such contact exists.
        // Note: This is an optional helper function
        Contact get(NodePtr node, string key) const;

        // Removes the node with the specified key from the specified tree
        void remove(NodePtr& node, string key);

        // Removes the root node of the specified tree.
        void remove_root(NodePtr& node);

        // Removes the node with the smallest key from the specified tree and
        // returns a pointer to that node.
        NodePtr remove_min(NodePtr& node);

		void traverse_infix(NodePtr node, vector<Contact>& v) const;

        // Adds the the Contacts in the specified tree, whose key is prefixed
        // by 'prefix', to the vector v. The contacts are ordered by their keys
        // in increasing order.
        // Uncomment for part C.
        void prefix_search(NodePtr node, string prefix, vector<Contact>& v) const;
};

using namespace std;

struct TreeNode
{
    TreeNode(int data, TreeNode *left = NULL, TreeNode *right = NULL);

    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

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

        friend ostream& operator<< (ostream& outs, IntSet set);

    private:
        NodePtr root;

        int size(NodePtr node);
        int min(NodePtr node);
        bool contains(NodePtr node, int item);
        void insert(NodePtr& node, int item);
        void print_inorder(ostream& outs,  NodePtr& node);
};

IntSet::IntSet()
{
    root = NULL;
}

IntSet::~IntSet()
{
    //Important!
}

int IntSet::size()
{
    return size(root);
}

int IntSet::size(NodePtr node)
{
    if(node == NULL) {
        return 0;
    }
    return size(node->left) + size(node->right);
}

bool IntSet::empty()
{
    return root == NULL;
}


bool IntSet::contains(int item)
{
    return contains(root, item);
}

bool IntSet::contains(NodePtr node, int item)
{
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

void IntSet::insert(int item)
{
    insert(root, item);
}

void IntSet::insert(NodePtr& node, int item)
{
    if(node == NULL || node->data == item) {
        node = new TreeNode(item);
        return;
    }
    if(item < node->data) {
        insert(node->left, item);
    } else {
        insert(node->right, item);
    }
}

void IntSet::remove(int item)
{
    //TODO
}

int IntSet::min()
{
    return min(root);
}

int IntSet::min(NodePtr node)
{
    if(node== NULL) {
        return INT_MIN;
    }
    if(node->left == NULL) {
        return node->data;
    }
    return min(node->left);
}

void IntSet::print_inorder(ostream& outs, NodePtr& node)
{
    if(node != NULL) {
        print_inorder(outs, node->left);
        outs << node->data << " ";
        print_inorder(outs, node->right);
    }
}

ostream& operator<< (ostream& outs, IntSet set)
{
    set.print_inorder(outs, set.root);
    return outs;
}

int main()
{
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
        s.insert(rand());
    }

    cout << "Done inserting" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;

    cout << "Querying" << endl;

    start = clock();

    for(int i = 0; i != 10000000; i++) {
        s.contains(i);
    }

    cout << "Done querying" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;
}
