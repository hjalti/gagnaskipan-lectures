#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

typedef Node* NodePtr;

class EmptyStackException { };

class IntStack
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
        NodePtr head;
};


IntStack::IntStack() {
    head = NULL;
}


bool IntStack::empty() {
    return (head == NULL);
}


void IntStack::push(int item) {
    NodePtr tmp;
    tmp = new Node();

    tmp->data = item;

    tmp->link = head;
    head = tmp;
}

int IntStack::pop() {
    if(empty()) {
        throw EmptyStackException();
    }

    int top = head->data;
    NodePtr tmp = head;
    head = head->link;
    delete tmp;

    return top;
}

int IntStack::top() {
    return head->data;
}
