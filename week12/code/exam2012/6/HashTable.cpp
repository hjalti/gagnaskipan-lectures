#include <iostream>
#include "HashTable.h"

using namespace std;

template <class T>
HashTable<T>::HashTable()
{
    // Initialize all the buckets with NULL pointers
    for (int i=0; i<TABLE_SIZE; i++)
        table[i] = NULL;
}

template <class T>
HashTable<T>::~HashTable()
{
    for (int i=0; i<TABLE_SIZE; i++) // delete all the lists
    {
        if (table[i] != NULL)
            table[i]->clear(); // Clear the linked list (this calls the destructors)
        delete table[i]; // De-allocated te pointer to the linked list
    }
}

// The hash function. Hashes the key into an integer
template <class T>
int HashTable<T>::hash(string key)
{
    int sum = 0;
    // Add the ASCII codes of the characters in the key
    for (unsigned int i=0; i<key.size(); i++)
    {
        char ch = key.at(i);
        sum = sum + ch;
    }
    return (sum % TABLE_SIZE); // Perform modulo division
}

template <class T>
T* HashTable<T>::find(string key)
{
    int pos = hash(key);
    if(table[pos] == NULL) {
        return NULL;
    }
    for(typename list<myPair*>::iterator it = table[pos]->begin();
        it != table[pos]->end(); it++) {
            if((*it)->first == key) {
                return &(*it)->second;
            }
    }
    return NULL;
}

template <class T>
void HashTable<T>::insert(string theKey, T& theValue) throw (HashException)
{
    T* val = find(theKey);
    if(val != NULL) {
        *val = theValue;
    } else {
        int pos = hash(theKey);
        if(table[pos] == NULL) {
            table[pos] = new list<myPair*>;
        }
        table[pos]->push_back(new pair<string,T>(theKey, theValue));
    }
}
