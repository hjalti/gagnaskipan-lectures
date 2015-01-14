#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector() {
    // TODO: Implement
}

IntVector::IntVector(int size, int value) {
    // TODO: Implement
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count){
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}


IntVector::~IntVector() {
    // TODO: Implement
}

// Public member functions

void IntVector::push_back(int elem) {
    // TODO: Implement
}

void IntVector::insert(int index, int elem) {
    // TODO: Implement
}

int IntVector::at(int index) const {
    // TODO: Implement
    return 0;
}

void IntVector::set_value_at(int index, int elem) const {
    // TODO: Implement
}

int IntVector::size() const {
    // TODO: Implement
    return 0;
}

bool IntVector::empty() const {
    // TODO: Implement
    return false;
}

void IntVector::remove_at(int index) {
    // TODO: Implement
}

int IntVector::pop_back() {
    // TODO: Implement
    return 0;
}

void IntVector::clear() {
    // TODO: Implement
}

// Overloaded operators

void IntVector::operator=(const IntVector& vec) {
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index) const {
    // TODO: Throw exception if index is out of range.
    return array[index];
}

ostream& operator<< (ostream& out, const IntVector& rhs) {
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs[i];
    }
    return out;
}
