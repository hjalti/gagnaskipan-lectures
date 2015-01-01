#include <iostream>
#include <vector>

using namespace std;

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
        vector<int> vec;
};


IntStack::IntStack()
{
    //empty;
}


bool IntStack::empty()
{
    return vec.empty();
}


void IntStack::push(int item)
{
    vec.push_back();
}

int IntStack::pop()
{
    return vec.pop_back();
}

int IntStack::top()
{
    return vec[vec.size() - 1];
}
