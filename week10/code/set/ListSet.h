#ifndef SETLIST_H
#define SETLIST_H

#include <list>

#include "Set.h"

using namespace std;

template<class T>
class ListSet : public Set<T>
{
    public:
        // Contstructs a new set
        ListSet();

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

    private:
        list<T> lis;
};


template<class T>
ListSet<T>::ListSet() { }

template<class T>
int ListSet<T>::size()
{
    return lis.size();
}

template<class T>
bool ListSet<T>::contains(T item)
{
    for(typename list<T>::iterator it = lis.begin(); it != lis.end(); ++it) {
        if(*it == item) {
            return true;
        }
    }
    return false;
}

template<class T>
void ListSet<T>::insert(T item)
{
    lis.push_back(item);
}

template<class T>
void ListSet<T>::remove(T item)
{
    lis.remove(item);
}

#endif

