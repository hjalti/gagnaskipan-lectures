#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <climits>

using namespace std;

const int INITIAL_SIZE = 64;

struct Pair
{
    Pair(string key, int value);

    string key;
    int value;
};

Pair::Pair(string key, int value)
{
    this->key = key;
    this->value = value;
}

// djb2
unsigned int hash(string s) {
    unsigned int hash = 5381;
    for(size_t i = 0; i < s.size(); i++) {
        hash = hash * 33 + static_cast<unsigned int>(s[i]);
    }
    return hash;
}

class KeyException { };

typedef Pair* PairPtr;

class StringIntMap
{
    public:
        // Contstructs a new map
        StringIntMap();

        ~StringIntMap();

        // Returns the number of elements in the map.
        int size();

        bool empty();

        // Adds the specified key to the map associated with the specified
        // value.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(string item, int key);

        // Removes the value associated with the specified key.
        // or
        // Removes the pair with the specified key.
        // NOT IMPLEMENTED
        void remove(string key);

        // Retrieves the item associated with the specified key.
        int& get(string key);

        // Returns true if and only if the map contains the specified key.
        bool contains(string key);

        int& operator[](string key);

        friend ostream& operator << (ostream& out, StringIntMap& m);

    private:
        PairPtr *map;
        int capacity;
        int count;

        int hash_key(string key);
        int get_pos(string key);
        void rebuild();
        void load_check();
};

StringIntMap::StringIntMap()
{
    capacity = INITIAL_SIZE;
    count = 0;
    map = new PairPtr[INITIAL_SIZE];
    for(int i = 0; i < capacity; i++) {
        map[i] = NULL;
    }
}

StringIntMap::~StringIntMap()
{
    for(int i = 0; i < capacity; i++) {
        if(map[i] != NULL) {
            delete map[i];
            map[i] = NULL;
        }
    }
    delete [] map;
}

int StringIntMap::size()
{
    return count;
}

int StringIntMap::hash_key(string key)
{
    return hash(key) % capacity;
}

void StringIntMap::load_check() {
    if(count / static_cast<double>(capacity) > 0.8) {
        rebuild();
    }
}

void StringIntMap::rebuild() {
    PairPtr *old_map = map;
    int old_cap = capacity;

    capacity *= 2;
    map = new PairPtr[capacity];

    for(int i = 0; i < capacity; i++) {
        map[i] = NULL;
    }

    for(int i = 0; i < old_cap; i++) {
        if(old_map[i] != NULL) {
            add(old_map[i]->key, old_map[i]->value);
            delete old_map[i];
        }
    }

    delete [] old_map;
}

bool StringIntMap::empty()
{
    return count == 0;
}


bool StringIntMap::contains(string key)
{
    return map[get_pos(key)] != NULL;
}

int StringIntMap::get_pos(string key)
{
    int h = hash_key(key);
    while(map[h] != NULL) {
        if(map[h]->key == key) {
            break;
        }
        h = (h + 1) % capacity;
    }
    return h;
}

int& StringIntMap::get(string key)
{
    int pos = get_pos(key);
    if(map[pos]!= NULL) {
        return map[pos]->value;
    }
    throw KeyException();
}

void StringIntMap::add(string key, int value)
{
    load_check();
    int pos = get_pos(key);
    if(map[pos]== NULL) {
        map[pos] = new Pair(key, value);
        count++;
    } else {
        map[pos]->value = value;
    }
}

void StringIntMap::remove(string key)
{
    // Nope
}

int& StringIntMap::operator[] (string key)
{
    if(!contains(key)) {
        add(key, 0);
    }
    return get(key);
}

ostream& operator<< (ostream& out, StringIntMap& m)
{
    for(int i = 0; i < m.capacity; i++) {
        if(m.map[i] != NULL) {
            out << m.map[i]->key << ": " << m.map[i]->value << endl;
        }
    }
    return out;
}

int main()
{
    StringIntMap m;
    string s;
    while(cin >> s) {
        m[s]++;
    }
    cout << m;
}
