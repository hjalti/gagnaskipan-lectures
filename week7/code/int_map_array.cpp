#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Data
{
    string value;
};

typedef Data* ValueType;

typedef int KeyType;

class Map
{
    public:
        Map(int capacity);

        ~Map();

        // Returns the number of items in this map
        int size();

        // Adds the specified key to the map associated with the specified
        // value.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        // or
        // Adds the (key, value) pair to the map. If a pair exists with the
        // same key, it is replaced with the new pair.
        void add(KeyType key, ValueType value);

        // Removes the value associated with the specified key.
        // or
        // Removes the pair with the specified key.
        void remove(KeyType key);

        // Retrieves the item associated with the specified key.
        // If no item is associated with the key:
        //     * NULL is returned (if ValueType is a pointer, this is an
        //     option),
        //     * Exception is thrown (if ValueType is not a pointer).
        ValueType get(KeyType key);

        // Returns true if and only if the map contains the specified key.
        bool contains(KeyType key);

    private:
        ValueType *map;
        int count;
        int capacity;

        void reset_key(KeyType key);
};

Map::Map(int capacity)
{
    map = new ValueType[capacity];
    count = 0;
    this->capacity = capacity;
    for(int i = 0; i < capacity; i++)
    {
        map[i] = NULL;
    }
}

Map::~Map()
{
    for(int i = 0; i < capacity; i++) {
        reset_key(i);
    }
    delete [] map;
}

void Map::reset_key(KeyType key)
{
    ValueType old_value = map[key];
    if(old_value != NULL) {
        count--;
        delete old_value;
    }
}

int Map::size()
{
    return count;
}

void Map::add(KeyType key, ValueType value)
{
    reset_key(key);
    map[key] = value;
    count++;
}

void Map::remove(KeyType key)
{
    reset_key(key);
    map[key] = NULL;
}

ValueType Map::get(KeyType key)
{
    return map[key];
}

bool Map::contains(KeyType key)
{
    return get(key) != NULL;
}

string random_string()
{
    int size = rand() % 30;
    string s;
    for(int i = 0; i < size; i++) {
        s.push_back(rand() % 26 + 97);
    }
    return s;
}

int main()
{
    srand(1337);
    Map map(100);

    for(int i = 0; i < 30; i++)
    {
        Data *data = new Data;
        data->value = random_string();
        map.add(rand() % 100, data);
    }

    for(int i = 0; i < 100; i++)
    {
        cout << setw(3) << i << ": ";
        Data *data = map.get(i);
        if(data == NULL) {
            cout << "-";
        } else {
            cout << data->value;
        }
        cout << endl;
    }

    return 0;
}
