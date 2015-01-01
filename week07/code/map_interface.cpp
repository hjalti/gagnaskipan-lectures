struct Data
{
    // Contains data
};

typedef Data ValueType;

typedef int KeyType;

class Map
{
    public:
        Map();

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
        // ??
};
