#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 50;

class IntStack()
{
    public:
        // Initializes an empty stack.
        IntStack();

        // Determines whether the stack is empty.
        bool empty();

        // Adds 'item' to the top of the stack.
        void push(int item);

        // Removes the top of the stack (i.e. removes the element that was added
        // most recently), and returns it.
        int pop();

        // Retrieves the top of the stack.
        int top();

    private:
		// A dynamic array of integers.
		int* array;
		// Contains the size of array (i.e. the maximum number of elements
		// that the vector can store using this array).
		int  capacity;
		// The number of array positions currently holding values.
		int  count;

		bool full() const;
		void grow();
}

bool IntStack::full() const
{
    return (count == capacity);
}

void IntStack::grow()
{
    capacity *= 2;
    int *new_array = new int[capacity];

    for(int i = 0; i < count; i++)
    {
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
}


IntStack::IntStack()
{
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
}


bool IntStack::empty()
{
    return (count == 0);
}


void IntStack::push(int item)
{
    if(full())
    {
        grow();
    }
    array[count] = elem;
    count++;
}

int IntStack::pop()
{
    count--;
    return array[count];
}

int IntStack::top()
{
    return array[count-1];
}
