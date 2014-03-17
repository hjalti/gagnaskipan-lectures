#ifndef BSVECTORSET_H
#define BSVECTORSET_H

#include <vector>

#include "Set.h"

using namespace std;

template<class T>
class BsVectorSet : public Set<T>
{
    public:
        // Contstructs a new set
        BsVectorSet();

        // Returns the number of (distinct) elements in the set.
        virtual int size();

        // Returns true if and only if the set contains 'item'.
        virtual bool contains(T item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        virtual void insert(T item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        virtual void remove(T item);

		bool empty();

    private:
        vector<T> vec;

        int insertion_index(T item);
        bool item_present(int index, T item);
};

template<class T>
BsVectorSet<T>::BsVectorSet() { }

template<class T>
int BsVectorSet<T>::size()
{
    return vec.size();
}

template<class T>
bool BsVectorSet<T>::empty()
{
    return size() == 0;
}

// Returns true if and only if 'item' is present at 'index' in vector.
template<class T>
bool BsVectorSet<T>::item_present(int index, T item)
{
    return index != size() && vec[index] == item;
}

// Returns the index before which 'item' should be inserted, in order to
// maintain the strict increasing order of vec.
// If 'item' is in vec, then the index of 'item' is returned.
template<class T>
int BsVectorSet<T>::insertion_index(T item)
{
    int l = 0;
    int r = vec.size() - 1;
    int m;

    while(l <= r)
    {
        m = (l + r) / 2;
        if(vec[m] == item) {
            return m;
        } else if (vec[m] < item) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

template<class T>
bool BsVectorSet<T>::contains(T item)
{
    int ind = insertion_index(item);
    return item_present(ind, item);
}

template<class T>
void BsVectorSet<T>::insert(T item)
{
    int ind = insertion_index(item);
    if(!item_present(ind, item)) {
        vec.insert(vec.begin() + ind, item);
    }
}

template<class T>
void BsVectorSet<T>::remove(T item)
{
    int ind = insertion_index(item);
    if(item_present(ind, item)) {
        vec.erase(vec.begin() + ind);
    }
}

#endif
