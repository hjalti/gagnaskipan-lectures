#include "VectorIntList.h"
#include <iostream>

using namespace std;

VectorIntList::VectorIntList() {
    index = 0;
}

// Clear contents from the list, to make it empty.
void VectorIntList::clear() {
    vec.clear();
}

// Insert an element at the current location.
// item: The element to be inserted
void VectorIntList::insert(const int& item) {
    vec.insert(vec.begin() + index, item);
}

// Append an element at the end of the list.
// item: The element to be appended.
void VectorIntList::append(const int& item) {
    vec.push_back(item);
}

// Remove and return the current element.
// Return: the element that was removed.
int VectorIntList::remove() {
    vec.erase(vec.begin() + index);
}

// Set the current position to the start of the list
void VectorIntList::moveToStart() {
    index = 0;
}

// Set the current position to the end of the list
void VectorIntList::moveToEnd() {
    index = vec.size() - 1;
}

// Move the current position one step left. No change
// if already at beginning.
void VectorIntList::prev() {
    index = max(0, index - 1);
}

// Move the current position one step right. No change
// if already at end.
void VectorIntList::next() {
    index = min(static_cast<int>(vec.size() - 1), index + 1);
}

// Return: The number of elements in the list.
int VectorIntList::length() const {
    return vec.size();
}

// Return: The position of the current element.
int VectorIntList::currPos() const {
    return index;
}

// Set current position.
// pos: The position to make current.
void VectorIntList::moveToPos(int pos) {
    index = pos;
}

// Return: The current element.
const int& VectorIntList::getValue() const {
    return vec.at(index);
}

ostream& operator<< (ostream& out, const VectorIntList& lis) {
    for(int i = 0; i < lis.vec.size(); i++) {
        out << lis.vec[i] << " ";
    }
    cout << endl;
}

