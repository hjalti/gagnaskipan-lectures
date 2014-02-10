#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int item)
{
    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->item = item;
    tmp_ptr->link = head;
    head = tmp_ptr;

}

void print(NodePtr head)
{
    if(head == NULL) {
        cout << endl;
    } else {
        cout << head->item << " ";
        print(head->link);
    }
}

void print_rev(NodePtr head)
{
    if(head != NULL) {
        print_rev(head->link);
        cout << head->item << " ";
    }
}

int size(NodePtr head)
{
    if(head == NULL) {
        return 0;
    }

    return 1 + size(head->link);
}

int sum(NodePtr head)
{
    if(head == NULL) {
        return 0;
    }

    return head->item + sum(head->link);
}


NodePtr search(NodePtr head, int target)
{
    NodePtr iter;
    for(iter = head; iter != NULL; iter = iter->link) {
        if(iter-> item == target) {
            return iter;
        }
    }
    return NULL;
}


int main()
{
    NodePtr head = NULL;

    for(int i = 0; i != 10; i++)
    {
        head_insert(head, i*i);
    }

    print(head);
    cout << size(head) << endl;
    cout << sum(head) << endl;
    print_rev(head);
    cout << endl;
}

