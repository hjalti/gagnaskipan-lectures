#include <iostream>

using namespace std;

class EmptyStackException { };

class NoMoreElementsException { };

template<class T>
class Iterator
{
    public:
        virtual ~Iterator() { }
        virtual bool has_next() = 0;
        virtual T next() = 0;
};

template<class T>
class Stack
{
    private:
		template<class U>
		struct Node
		{
			U data;
			Node<T> *link;
		};

        Node<T> *head;

        class StackIterator : public Iterator<T>
        {
            public:
                StackIterator(Stack<T>& st);
                ~StackIterator() { };
                bool has_next();
                T next();
            private:
                Node<T> *curr;

        };

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

        Iterator<T>* iter();
};

template<class T>
Stack<T>::StackIterator::StackIterator(Stack<T>& st)
{
    curr = st.head;
}

template<class T>
bool Stack<T>::StackIterator::has_next()
{
    return curr != NULL;
}

template<class T>
T Stack<T>::StackIterator::next()
{
    if(!has_next()) {
        throw NoMoreElementsException();
    }
    T data = curr->data;
    curr = curr->link;
    return data;
}

template<class T>
Iterator<T>* Stack<T>::iter()
{
    return new StackIterator(*this);
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
    Node<T> *tmp = new Node<T>();
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
    Node<T> *next = head->link;
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
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(3);
    Iterator<int>* it = s.iter();
    while(it->has_next()) {
        cout << it->next() << endl;
    }

}
