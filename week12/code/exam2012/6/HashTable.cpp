#include <iostream>
#include "hashtable.h"

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
    int sum=0;
    // Add the ASCII codes of the characters in the key
    for (unsigned int i=0; i<key.size(); i++)
    {
        char ch = key.at(i);
        sum = sum + ch;
    }
    return (sum % TABLE_SIZE); // Perform modulo division
}
