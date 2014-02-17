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

class PointSet
{
    public:
        // Contstructs a new set
        PointSet();

        ~PointSet();

        // Returns the number of (distinct) elements in the set.
        int size();

        bool empty();

        // Returns true if and only if the set contains 'item'.
        bool contains(Point item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        void insert(Point tem);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        void remove(Point item);

    private:
        NodePtr root;

        int size(NodePtr node);
        bool contains(NodePtr node, Point item);
        void insert(NodePtr& node, Point item);
};

PointSet::PointSet()
{
    root = NULL;
}

PointSet::~PointSet()
{
    //Important!
}

int PointSet::size()
{
    return size(root);
}

int PointSet::size(NodePtr node)
{
    if(node == NULL) {
        return 0;
    }
    return size(node->left) + size(node->right);
}

bool PointSet::empty()
{
    return root == NULL;
}


bool PointSet::contains(Point item)

{
    return contains(root, item);
}

bool PointSet::contains(NodePtr node, Point item)
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

void PointSet::insert(Point item)
{
    insert(root, item);
}

void PointSet::insert(NodePtr& node, Point item)
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

void PointSet::remove(Point item)
{
    //TODO
}


int main()
{
    srand(137872);

    PointSet s;
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
