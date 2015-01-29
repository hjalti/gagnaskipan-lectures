#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

typedef Node* NodePtr;

class EmptyStackException {};

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
        void empty_check();

        NodePtr head;
};

IntStack::IntStack() {
    head = NULL;
}

void IntStack::empty_check() {
    if(empty())
    {
        throw EmptyStackException();
    }
}

bool IntStack::empty() {
    return head == NULL;
}

void IntStack::push(int item) {
    NodePtr new_node = new Node();

    new_node->link = head;
    new_node->data = item;

    head = new_node;
}

int IntStack::pop() {
    empty_check();

    NodePtr tmp = head;
    head = head->link;
    int top = tmp->data;

    delete tmp;

    return top;
}

int IntStack::top() {
    empty_check();

    return head->data;
}

int main() {
    IntStack stack;

    int curr;
    char oper;
    char tmp;
    int right, left;

    while(cin >> tmp) {
        if(isdigit(tmp)) {
            cin.putback(tmp);
            cin >> curr;
            stack.push(curr);
        } else {
            oper = tmp;
            right = stack.pop();
            left = stack.pop();
            switch (oper) {
                case '+':
                    stack.push(left + right);
                    break;
                case '-':
                    stack.push(left - right);
                    break;
                case '*':
                    stack.push(left * right);
                    break;
            }
        }
    }

    cout << stack.top() << endl;

    return 0;
}
