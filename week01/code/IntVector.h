#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 50;

class IndexOutOfRangeException {};
class EmptyException {};

class IntVector
{
	private:
		// A dynamic array of integers.
		int* array;
		// Contains the size of array (i.e. the maximum number of elements
		// that the vector can store using this array).
		int  capacity;
		// The number of array positions currently holding values.
		int  count;

	public:
		// Initializes an empty vector.
		IntVector();
		// Initializes a vector with 'size' copies of the element 'value'.
		// If 'size' is less than 0, the initalized vector is empty.
		IntVector(int size, int value = 0);
		// A copy constructor.
		IntVector(const IntVector& vec);
		// A destructor.
		~IntVector();

		// Returns the element at position 'index'.
		int  at(int index) const;
		// Sets the value at position 'index' to 'elem'.
		void set_value_at(int index, int elem) const;

		// Returns the size of the array.
		int  size() const;
		// Returns true if and only if the array contains no elements.
		bool empty() const;

		// Appends elem to the vector.
		void push_back(int elem);
		// Removes the last element of the vector and returns it.
		int  pop_back();
		// Inserts 'elem' into the list at position 'index'. All elements to the
		// right of index are shifted one position to the right.
		void insert(int index, int elem);
		// Removes the element at position 'index'. All elements to the
		// right of index are shifted one position to the left.
		void remove_at(int index);
		// Removes all the elements from the list
		void clear();

		// Overloaded = operator.
		void operator=(const IntVector& vec);
		// Returns a reference to the element at position 'index'.
		int& operator[] (int index) const;
};

ostream& operator<< (ostream& out, const IntVector& rhs);

#endif
