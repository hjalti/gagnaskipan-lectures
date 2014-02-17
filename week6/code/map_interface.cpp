struct Item
{
    // Contains data
};

class Map
{
    public:
        Map();

        ~Map();

        // Returns the number of items in this map
        int size();

        // Inserts the item into the map and associates it with the specified key.
        void insert(int key, Item *value);

        // Removes the item associated with the specified key.
        void remove(int key, Item *value);

        // Retrieves the item associated with the specified key.
        // If no item is associated with the key, NULL is returned.
        Item* search(int key);

    private:
        // ??
};
