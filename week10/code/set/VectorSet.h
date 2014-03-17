#ifndef VECTORSET_H
#define VECTORSET_H

#include <vector>

using namespace std;

template<class T>
class VectorSet : public Set<T>
{
    public:
        // Contstructs a new set
        VectorSet();

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
        vector<T> vec;

        int index(T item);
};


template<class T>
VectorSet<T>::VectorSet() { }

template<class T>
int VectorSet<T>::size()
{
    return vec.size();
}

template<class T>
int VectorSet<T>::index(T item)
{
    for(size_t i = 0; i != vec.size(); i++) {
        if(vec[i] == item) {
            return i;
        }
    }
    return -1;
}

template<class T>
bool VectorSet<T>::contains(T item)
{
    return (index(item) != -1);
}

template<class T>
void VectorSet<T>::insert(T item)
{
    vec.push_back(item);
}

template<class T>
void VectorSet<T>::remove(T item)
{
    int ind = index(item);
    while(ind != -1) {
        vec.erase(vec.begin() + ind);
        ind = index(item);
    }
}

#endif
