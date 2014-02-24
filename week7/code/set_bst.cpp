#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

struct Data
{
    // Anything can go here
}

typedef Data ValueType;

typedef int KeyType;

struct TreeNode
{
    TreeNode(KeyType key, ValueType value, TreeNode *left = NULL, TreeNode *right = NULL);

    // The (key,value) pair.
    KeyType key;
    ValueType value;

    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(KeyType key, ValueType value, TreeNode *left, TreeNode *right)
{
    this->key = key;
    this->value = value;

    this->left = left;
    this->right = right;
}

typedef TreeNode* NodePtr;

class Map
{
    public:
        // Contstructs a new map
        Map();

        ~Map();

        // Returns the number of elements in the map.
        int size();

        bool empty();

        // Adds the specified key to the map associated with the specified
        // value.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(KeyType item, ValueType value);

        // Removes the value associated with the specified key.
        // or
        // Removes the pair with the specified key.
        void remove(KeyType key);

        // Retrieves the item associated with the specified key.
        bool get(KeyType key);

        // Returns true if and only if the map contains the specified key.
        bool contains(KeyType key);


    private:
        NodePtr root;

        int size(NodePtr node);
        int min(NodePtr node);
};

Map::Map()
{
    root = NULL;
}

Map::~Map()
{
    //Important!
}

int Map::size()
{
    return size(root);
}

int Map::size(NodePtr node)
{
    if(node == NULL) {
        return 0;
    }
    return size(node->left) + size(node->right);
}

bool Map::empty()
{
    return root == NULL;
}


bool Map::contains(KeyType item)
{
}

void Map::insert(KeyType key, ValueType value)
{
}

void Map::remove(KeyType key)
{
}

int main()
{
}
