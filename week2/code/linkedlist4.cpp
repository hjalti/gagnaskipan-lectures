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

int main()
{
    NodePtr head;
    NodePtr next;

    head = new Node;
    head->count = 5;
    head->link = NULL;

    head_insert(head, 10);
    cout << head->item << endl;

    next = head->link;
    if (next != NULL)
        cout << next->item << endl;

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
