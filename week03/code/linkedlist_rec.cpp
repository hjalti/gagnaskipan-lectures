#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int data);
void print(NodePtr head);
NodePtr search(NodePtr head, int target);
void insert(NodePtr after_me, int data);
void head_remove(NodePtr& head);
void remove_all(NodePtr head);

int main() {
    NodePtr head = NULL;

    for(int i = 0; i != 10; i++) {
        head_insert(head, i*i);
    }

    print(head);
    NodePtr result;
    result = search(head, 81);
    insert(result, 35);
    print(head);
    insert(search(head,0), 42);
    print(head);
    for(int i = 0; i != 3; i++) {
        head_remove(head);
    }
    print(head);
    remove_all(head);
}

void head_insert(NodePtr& head, int data) {
    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->data = data;
    tmp_ptr->link = head;
    head = tmp_ptr;

}

void print(NodePtr head) {
    if(head == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << head->data << "::";
        print(head->link);
    }

}

NodePtr search(NodePtr head, int target) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == target) {
        return head;
    }
    return search(head->link, target);
}

void insert(NodePtr after_me, int data) {
    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->data = data;

    tmp_ptr->link = after_me->link;
    after_me->link = tmp_ptr;
}

void head_remove(NodePtr& head) {
    if(head == NULL) {
        return;
    }

    NodePtr old_head = head;
    head = head->link;

    delete old_head;
}

void remove_all(NodePtr head) {
    if (head == NULL) {
        return;
    }
    remove_all(head->link);
    delete head;
}
