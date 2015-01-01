#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

struct Point
{
    Point(int x = 0, int y = 0);

    int x;
    int y;
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool operator< (const Point& lhs, const Point& rhs)
{
    return (lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y));
}

bool operator== (const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

typedef Point ValueType;

struct TreeNode
{
    TreeNode(Point data, TreeNode *left = NULL, TreeNode *right = NULL);

    Point data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(Point data, TreeNode *left, TreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

typedef TreeNode* NodePtr;

class Set
{
    public:
        // Contstructs a new set
        Set();

        ~Set();

        // Returns the number of (distinct) elements in the set.
        int size();

        bool empty();

        // Returns true if and only if the set contains 'item'.
        bool contains(ValueType item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        void insert(ValueType tem);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        void remove(ValueType item);

    private:
        NodePtr root;

        int size(NodePtr node);
        bool contains(NodePtr node, ValueType item);
        void insert(NodePtr& node, ValueType item);
};

Set::Set()
{
    root = NULL;
}

Set::~Set()
{
    //Important!
}

int Set::size()
{
    return size(root);
}

int Set::size(NodePtr node)
{
    if(node == NULL) {
        return 0;
    }
    return size(node->left) + size(node->right);
}

bool Set::empty()
{
    return root == NULL;
}


bool Set::contains(ValueType item)

{
    return contains(root, item);
}

bool Set::contains(NodePtr node, ValueType item)
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

void Set::insert(ValueType item)
{
    insert(root, item);
}

void Set::insert(NodePtr& node, ValueType item)
{
    if(node == NULL) {
        node = new TreeNode(item);
        return;
    }
    if(item < node->data) {
        return insert(node->left, item);
    }
    return insert(node->right, item);
}

void Set::remove(ValueType item)
{
    //TODO
}


int main()
{
    srand(1337);

    Set s;
    for(int i = 0; i != 20; i++) {
        s.insert(Point(rand() % 30, rand() % 30));
    }

    for(int i = 0; i != 30; i++) {
        for(int j = 0; j != 30; j++) {
            if(s.contains(Point(i, j))) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }

    clock_t start = clock();

    for(int i = 0; i != 1000000; i++) {
        s.insert(Point(rand(), rand()));
    }

    cout << "Done inserting" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;

    cout << "Querying" << endl;

    start = clock();


    for(int i = 0; i != 10000; i++) {
        for(int j = 0; j != 1000; j++) {
            s.contains(Point(i,j));
        }
    }

    cout << "Done querying" << endl;
    cout << "Time: " << ((clock()- start) / (double) CLOCKS_PER_SEC) << "s" << endl;
}
