#ifndef ORDEREDVECTORSET_H
#define ORDEREDVECTORSET_H

#include <vector>

#include "Set.h"

using namespace std;

template<class T>
class OrderedVectorSet : public Set<T>
{
    public:
        // Contstructs a new set
        OrderedVectorSet();

        // Returns the number of (distinct) elements in the set.
        virtual int size();

        virtual bool empty();

        // Returns true if and only if the set contains 'item'.
        virtual bool contains(T item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        virtual void insert(T item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        virtual void remove(T item);

    private:
        vector<T> vec;

        int insertion_index(T item);
        bool item_present(int index, T item);
};

template<class T>
OrderedVectorSet<T>::OrderedVectorSet() { }

template<class T>
int OrderedVectorSet<T>::size()
{
    return vec.size();
}

template<class T>
bool OrderedVectorSet<T>::empty()
{
    return size() == 0;
}

// Returns true if and only if 'item' is present at 'index' in vector.
template<class T>
bool OrderedVectorSet<T>::item_present(int index, T item)
{
    return index != size() && vec[index] == item;
}

// Returns the index before which 'item' should be inserted, in order to
// maintain the strict increasing order of vec.
// If 'item' is in vec, then the index of 'item' is returned.
template<class T>
int OrderedVectorSet<T>::insertion_index(T item)
{
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i] >= item) {
            return i;
        }
    }
    return vec.size();
}

template<class T>
bool OrderedVectorSet<T>::contains(T item)
{
    int ind = insertion_index(item);
    return item_present(ind, item);
}

template<class T>
void OrderedVectorSet<T>::insert(T item)
{
    int ind = insertion_index(item);
    if(!item_present(ind, item)) {
        vec.insert(vec.begin() + ind, item);
    }
}

template<class T>
void OrderedVectorSet<T>::remove(T item)
{
    int ind = insertion_index(item);
    if(item_present(ind, item)) {
        vec.erase(vec.begin() + ind);
    }
}

#endif
