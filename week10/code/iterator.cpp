#include <iostream>

using namespace std;

class EmptyStackException { };
class NoMoreElementsException { };

template<class T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node *link;
        };

        Node *head;

    public:
        // Initializes an empty stack.
        Stack();

        // Determines whether the stack is empty.
        bool empty();

        // Adds 'item' to the top of the stack.
        void push(T item);

        // Removes the top of the stack (i.e. removes the element that was added
        // most recently), and returns it.
        T pop();

        // Retrieves the top of the stack.
        T top();

        class Iterator
        {
            public:
                Iterator(Stack& s);
                T next();
                bool has_next();

            private:
                Stack<T>::Node *curr;

        };

        Iterator get_iterator();
};


template<class T>
Stack<T>::Iterator::Iterator(Stack<T>& s)
{
    curr = s.head;
}

template<class T>
T Stack<T>::Iterator::next()
{
    if(curr == NULL) {
        throw NoMoreElementsException();
    }
    T data = curr->data;
    curr = curr->link;
    return data;
}

template<class T>
bool Stack<T>::Iterator::has_next()
{
    return (curr != NULL);
}

template<class T>
typename Stack<T>::Iterator Stack<T>::get_iterator()
{
    return Iterator(*this);
}

template<class T>
Stack<T>::Stack()
{
    head = NULL;
}


template<class T>
bool Stack<T>::empty()
{
    return (head == NULL);
}

template<class T>
void Stack<T>::push(T item)
{
    Stack<T>::Node *tmp = new Stack<T>::Node();
    tmp->data = item;
    tmp->link = head;
    head = tmp;
}

template<class T>
T Stack<T>::pop()
{
    if(empty()) {
        throw EmptyStackException();
    }

    T t = head->data;
    Stack<T>::Node *next = head->link;
    delete head;
    head = next;
    return t;
}

template<class T>
T Stack<T>::top()
{
    if(empty()) {
        throw EmptyStackException();
    }
    return head->data;
}

int main()
{
    Stack<int> s;
    for(int i = 0; i < 10; i++) {
        s.push(i * i);
    }
    Stack<int>::Iterator it = s.get_iterator();
    while(it.has_next()) {
        cout << it.next() << endl;
    }

    return 0;
}
