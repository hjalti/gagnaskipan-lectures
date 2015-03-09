#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

///////////////////
// Set interface //
///////////////////

class IntSet
{
    public:
        // Returns the number of (distinct) elements in the set.
        virtual int size() = 0;

        virtual bool empty() = 0;

        // Returns true if and only if the set contains 'item'.
        virtual bool contains(int item) = 0;

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        virtual void insert(int item) = 0;

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        virtual void remove(int item) = 0;
};








///////////////////////////////////////
// Binary Search Tree Implementation //
///////////////////////////////////////



struct TreeNode
{
    TreeNode(int data, TreeNode *left = NULL, TreeNode *right = NULL)
        : data(data), left(left), right(right) { }

    int data;
    TreeNode *left;
    TreeNode *right;
};

typedef TreeNode* NodePtr;

class BstIntSet : public IntSet
{
    public:
        // Contstructs a new set
        BstIntSet();

        ~BstIntSet();

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

        friend ostream& operator<< (ostream& outs, const BstIntSet& set);

    private:
        NodePtr root;

        int size(NodePtr node);
        int min(NodePtr node);
        bool contains(NodePtr node, int item);
        void insert(NodePtr& node, int item);
        void clear(NodePtr node);
        void print_inorder(ostream& outs, NodePtr node) const;
        void remove(NodePtr& node, int item);
};

BstIntSet::BstIntSet() {
    root = NULL;
}

BstIntSet::~BstIntSet() {
    clear(root);
}

void BstIntSet::clear(NodePtr node) {
    if(node != NULL) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int BstIntSet::size() {
    return size(root);
}

int BstIntSet::size(NodePtr node) {
    if(node == NULL) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

bool BstIntSet::empty() {
    return root == NULL;
}

bool BstIntSet::contains(int item) {
    return contains(root, item);
}

bool BstIntSet::contains(NodePtr node, int item) {
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

void BstIntSet::insert(int item) {
    insert(root, item);
}

void BstIntSet::insert(NodePtr& node, int item) {
    if(node == NULL) {
        node = new TreeNode(item);
    } else if(item < node->data) {
        insert(node->left, item);
    } else if(item > node->data) {
        insert(node->right, item);
    }
}

void BstIntSet::remove(NodePtr& node, int item) {
    if(node == NULL) {
        return;
    } else if(item < node->data) {
        remove(node->left, item);
    } else if(item > node->data) {
        remove(node->right, item);
    } else {
        NodePtr to_del = node;
        if(node->left == NULL) {
            node = node->right;
        } else if (node->right == NULL) {
            node = node->left;
        } else {
            int new_val = min(node->right);
            remove(node, new_val);
            node->data = new_val;
            return;
        }
        delete to_del;
    }
}

void BstIntSet::remove(int item) {
    remove(root, item);
}

int BstIntSet::min() {
    return min(root);
}

int BstIntSet::min(NodePtr node) {
    if(node== NULL) {
        return INT_MIN;
    }
    if(node->left == NULL) {
        return node->data;
    }
    return min(node->left);
}

void BstIntSet::print_inorder(ostream& outs, NodePtr node) const {
    if(node != NULL) {
        print_inorder(outs, node->left);
        outs << node->data << " ";
        print_inorder(outs, node->right);
    }
}

ostream& operator<< (ostream& outs, const BstIntSet& set) {
    set.print_inorder(outs, set.root);
    return outs;
}



class BsVectorIntSet : public IntSet
{
    public:
        // Contstructs a new set
        BsVectorIntSet();

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

    private:
        vector<int> vec;

        int insertion_index(int item);
        bool item_present(int index, int item);
};

BsVectorIntSet::BsVectorIntSet() { }

int BsVectorIntSet::size() {
    return vec.size();
}

bool BsVectorIntSet::empty() {
    return size() == 0;
}

// Returns true if and only if 'item' is present at 'index' in vector.
bool BsVectorIntSet::item_present(int index, int item) {
    return index != size() && vec[index] == item;
}

// Returns the index before which 'item' should be inserted, in order to
// maintain the strict increasing order of vec.
// If 'item' is in vec, then the index of 'item' is returned.
int BsVectorIntSet::insertion_index(int item) {
    int l = 0;
    int r = vec.size() - 1;
    int m;

    while(l <= r) {
        m = (l + r) / 2;
        if(vec[m] == item) {
            return m;
        } else if (vec[m] < item) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if(empty()) {
        return 0;
    } else if(l == 0) {
        assert(item < vec[0]);
    } else if(l == size()) {
        assert(vec[size() - 1] < item);
    } else {
        assert(vec[l-1] < item && item < vec[l]);
    }
    return l;
}

bool BsVectorIntSet::contains(int item) {
    int ind = insertion_index(item);
    return item_present(ind, item);
}

void BsVectorIntSet::insert(int item) {
    int ind = insertion_index(item);
    if(!item_present(ind, item)) {
        vec.insert(vec.begin() + ind, item);
    }
}

void BsVectorIntSet::remove(int item) {
    int ind = insertion_index(item);
    if(item_present(ind, item)) {
        vec.erase(vec.begin() + ind);
    }
}





int main() {
    srand(137872);

    IntSet* s = new BsVectorIntSet();
    for(int i = 0; i != 20; i++) {
        s->insert(rand() % 30);
    }

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s->contains(i) ? "Yes" : "No") << endl;
        if (i % 2 == 0) {
            s->remove(i);
        }
    }
    cout << endl;

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s->contains(i) ? "Yes" : "No") << endl;
    }

    clock_t start = clock();

    for(int i = 0; i != 1000000; i++) {
        s->insert(rand());
    }

    for(int i = 0; i != 1000000; i++) {
        s->remove(rand());
    }

    cout << "Done inserting" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;

    cout << "Querying" << endl;

    start = clock();

    for(int i = 0; i != 1000000; i++) {
        s->contains(i);
    }

    cout << "Done querying" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;
}
