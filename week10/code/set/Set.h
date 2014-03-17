#ifndef SET_H
#define SET_H

template<class T>
class Set
{
    public:
        // Returns the number of (distinct) elements in the set.
        virtual int size() = 0;

        // Returns true if and only if the set contains 'item'.
        virtual bool contains(T item) = 0;

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        virtual void insert(T item) = 0;

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        virtual void remove(T item) = 0;
};

#endif
