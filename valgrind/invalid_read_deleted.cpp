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

        ~IntStack();

        // Determines whether the stack is empty.
        bool empty();

        // Adds 'item' to the top of the stack.
        void push(int item);

        // Removes the top of the stack (i.e. removes the element that was added
        // most recently), and returns it.
        int pop();

        // Retrieves the top of the stack.
        int top();

        // Clears the contents of the stack.
        void clear();
    private:
        NodePtr head;
};


IntStack::IntStack() {
    head = NULL;
}

IntStack::~IntStack() {
    clear();
}

void IntStack::clear() {
    NodePtr p = head;
    while(p != NULL) {
        NodePtr tmp = p;
        p = p->link;
        delete tmp;
    }
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
    if (empty()) {
        throw EmptyStackException();
    }
    int top = head->data;
    NodePtr tmp = head;
    head = head->link;
    delete tmp;

    return top;
}

int IntStack::top() {
    if (empty()) {
        throw EmptyStackException();
    }
    return head->data;
}

int main() {
    IntStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.clear();
    s.top();
    s.pop();
    return 0;
}
