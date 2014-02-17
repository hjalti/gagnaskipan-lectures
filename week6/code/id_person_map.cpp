#include <string>

using namespace std;

struct Person
{
    int id;
    string name;
    string address;
    string phone;
    string email;
}

struct MapNode
{
    string key;
    Person *value;

    MapNode *left;
    MapNode *right;
}

typedef MapNode* NodePtr;

class IdPersonMap
{
    IdPersonMap();

    ~IdPersonMap();

    // Returns the number of items in this map
    int size();

    // T
    int insert(int key, );
};
