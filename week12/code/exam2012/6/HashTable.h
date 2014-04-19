#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <utility> // For the pair class
#include "HashException.h"

using namespace std;

const int TABLE_SIZE = 37; // The number of buckets in the hash table (a prime!)

// This implementation of a Hash table uses a linked list (chaining) for collision resolution
// The key is assumed to be of type string but the template parameter T is used for the value.
// The value stored in the hash table is a pair<string,T>
template <class T>
class HashTable
{
	typedef pair<string, T> myPair;
	public:
		HashTable();
		~HashTable();
		void insert(string theKey, T& theValue) throw (HashException);
		// Insert an object with key theKey and value theValue
		T* find(string theKey);
		// Returns a pointer to the value found for key theKey, otherwise NULL
		void remove(string theKey) throw (HashException); // Removes the entry for key theKey

	private:
		int hash(string theKey); // The hash function. Hashes the key into an integer
		list<myPair*> *table[TABLE_SIZE]; // The hash table is an array of pointers to a linked list of pointers to pairs
};
#endif // HASHTABLE_H
