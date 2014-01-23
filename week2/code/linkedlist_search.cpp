#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int item);
// Creates a new Node with the given values and makes it the head of the given list
void print(NodePtr head);
// Prints the given list
NodePtr search(NodePtr head, int target);
// Returns a pointer to the first node in the list that contains 'target'. If
// no node contains 'target', the function returns NULL.


int main()
{
    NodePtr head = NULL;

    for(int i = 0; i != 10; i++)
    {
        head_insert(head, i*i);
    }

    print(head);
    NodePtr result;
    result = search(head, 81);
    if(result != NULL)
    {
        cout << "The list contains 81" << endl;
    }
    else
    {
        cout << "The list does not contain 81" << endl;
    }

    result = search(head, 37);
    if(result != NULL)
    {
        cout << "The list contains 37" << endl;
    }
    else
    {
        cout << "The list does not contain 37" << endl;
    }
}

void head_insert(NodePtr& head, int item)
// Creates a new Node with the given values and makes it the head of the given list
{
    NodePtr tmpPtr;
    tmpPtr = new Node;
    tmpPtr->item = item;
    tmpPtr->link = head;
    head = tmpPtr;

}

void print(NodePtr head)
{
    if(head == NULL)
    {
        cout << "<empty>" << endl;
    }

    NodePtr iter;
    for(iter = head; iter != NULL; iter = iter->link)
    {
        cout << iter->item << endl;
    }
}

NodPtr search(NodePtr head, int target)
{
    NodePtr iter;
    for(iter = head; iter != NULL; iter = iter->link)
    {
        if(iter-> item == target)
        {
            return iter;
        }
    }
    return NULL;
}
