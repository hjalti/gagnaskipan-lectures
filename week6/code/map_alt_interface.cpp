#include <string>

using namespace std;

struct Item
{
    // Contains data
}

struct MapNode
{
    int key;
    Item *value;

    MapNode *left;
    MapNode *right;
}

typedef MapNode* NodePtr;

class Map
{
    IdPersonMap();

    ~IdPersonMap();

    // Returns the number of items in this map
    int size();

    // Inserts 'item' into the map and associates it with the specified key.
    void insert(int key, Item *value);

    // Removes the item associated with the specified key.
    void delete(int key, Item *value);

    // Retrieves the item associated with the specified key.
    // If no item is associated with the key, NULL is returned.
    Item* search(int key);
};
