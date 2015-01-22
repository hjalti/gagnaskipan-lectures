// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef __VECTOR_INT_LIST_H__
#define __VECTOR_INT_LIST_H__

#include <vector>
#include <iostream>

using namespace std;

class VectorIntList { // IntList ADT
    private:
        vector<int> vec;
        int index;
    public:
        VectorIntList();

        // Clear contents from the list, to make it empty.
        void clear();

        // Insert an element at the current location.
        // item: The element to be inserted
        void insert(const int& item);

        // Append an element at the end of the list.
        // item: The element to be appended.
        void append(const int& item);

        // Remove and return the current element.
        // Return: the element that was removed.
        int remove();

        // Set the current position to the start of the list
        void moveToStart();

        // Set the current position to the end of the list
        void moveToEnd();

        // Move the current position one step left. No change
        // if already at beginning.
        void prev();

        // Move the current position one step right. No change
        // if already at end.
        void next();

        // Return: The number of elements in the list.
        int length() const;

        // Return: The position of the current element.
        int currPos() const;

        // Set current position.
        // pos: The position to make current.
        void moveToPos(int pos);

        // Return: The current element.
        const int& getValue() const;

        friend ostream& operator<< (ostream& out, const VectorIntList& lis);
};

#endif
