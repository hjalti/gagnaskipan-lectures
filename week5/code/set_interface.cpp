class IntSet
{
    public:
        // Contstructs a new set
        Set();

        // Returns the number of (distinct) elements in the set.
        int size();

        // Returns true if and only if the set contains 'item'.
        bool contains(int item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        void insert(int item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        void remove(int item);

    private:
        // ??
}
