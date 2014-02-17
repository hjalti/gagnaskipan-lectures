#include <string>

using namespace std;

struct Item
{
    // Data
};

typedef Item* ValueType;
typedef string KeyType;

struct MapNode
{
    MapNode(KeyType key, ValueType value, MapNode* left = NULL, MapNode* right = NULL);

    KeyType key;
    ValueType value;

    MapNode *left;
    MapNode *right;
};

MapNode::MapNode(KeyType key, ValueType value, MapNode* left, MapNode* right)
{
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
}

typedef MapNode* NodePtr;

class Map
{
    public:
        Map();

        ~Map();

        // Returns the number of items in this map
        int size();

        // Inserts the item into the map and associates it with the specified key.
        void insert(KeyType key, ValueType value);

        // Removes the item associated with the specified key.
        void remove(KeyType key);

        // Retrieves the item associated with the specified key.
        // If no item is associated with the key, NULL is returned.
        ValueType search(KeyType key);

    private:
        NodePtr root;

        int size(NodePtr node);
        ValueType search(NodePtr node, KeyType key);
        void insert(NodePtr& node, KeyType key, ValueType value);
};

Map::Map()
{
    root = NULL;
}

Map::~Map()
{
    // DESTROY!!
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


Item* Map::search(KeyType key)
{
    return search(root, key);
}

Item* Map::search(NodePtr node, KeyType key)
{
    if(node == NULL) {
        return NULL;
    }
    if(node->key == key) {
        return node->value;
    }
    if(key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);

}

void Map::insert(KeyType key, ValueType value)
{
    insert(root, key, value);
}

void Map::insert(NodePtr& node, KeyType key, ValueType value)
{
    if(node == NULL) {
        node = new MapNode(key, value);
        return;
    }
    if(key < node->key) {
        return insert(node->left, key, value);
    }
    return insert(node->right, key, value);
}

void Map::remove(KeyType key)
{
    //TODO
}


int main()
{
}
