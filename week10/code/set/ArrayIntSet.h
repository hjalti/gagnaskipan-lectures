#ifndef ARRAYINTSET_H
#define ARRAYINTSET_H

#include "Set.h"

class ElementOutOfRangeException { };

class ArrayIntSet : public Set<int>
{
    public:
        // Contstructs a new set
        ArrayIntSet(int max_capacity);

        ~ArrayIntSet();

        // Returns the number of (distinct) elements in the set.
        virtual int size();

        // Returns true if and only if the set contains 'item'.
        virtual bool contains(int item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        virtual void insert(int item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        virtual void remove(int item);

		int max_element();

    private:
        bool *array;
        int count;
		int capacity;

		bool out_of_range(int item);
};


ArrayIntSet::ArrayIntSet(int max_capacity)
{
    count = 0;
    array = new bool[max_capacity];
	capacity = max_capacity;

    for(int i = 0; i < max_capacity; i++)
    {
        array[i] = false;
    }
}

ArrayIntSet::~ArrayIntSet()
{
    delete [] array;
}

bool ArrayIntSet::out_of_range(int item)
{
	return item < 0 || item >= max_element();
}

int ArrayIntSet::size()
{
    return count;
}

bool ArrayIntSet::contains(int item)
{
	if(out_of_range(item)) {
		return false;
	}
    return array[item];
}

void ArrayIntSet::insert(int item)
{
	if(out_of_range(item)) {
		throw ElementOutOfRangeException();
	}
    array[item] = true;
}

void ArrayIntSet::remove(int item)
{
	if(!out_of_range(item)) {
		array[item] = false;
	}
}

int ArrayIntSet::max_element()
{
	return capacity - 1;
}

#endif
