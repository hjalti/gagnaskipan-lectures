#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int item);
void print(NodePtr head);
// Creates a new Node with the given values and makes it the head of the given list

int main()
{
    NodePtr head = NULL;

    for(int i = 0; i != 10; i++)
    {
        head_insert(head, i*i);
    }

    print(head);
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

    NodePtr curr = head;
    while(curr != NULL)
    {
        cout << curr->item << endl;
        curr = curr->link;
    }
}
