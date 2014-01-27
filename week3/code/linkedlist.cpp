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

NodePtr search(NodePtr head, int target);

void insert(NodePtr after_me, int item);


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
    insert(result, 35);
    print(head);
    insert(search(head,0), 42);
    print(head);
}

void head_insert(NodePtr& head, int item)
// Creates a new Node with the given values and makes it the head of the given list
{
    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->item = item;
    tmp_ptr->link = head;
    head = tmp_ptr;

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

NodePtr search(NodePtr head, int target)
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

void insert(NodePtr after_me, int item)
{
    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->item = item;

    tmp_ptr->link = after_me->link;
    after_me->link = tmp_ptr;
}
