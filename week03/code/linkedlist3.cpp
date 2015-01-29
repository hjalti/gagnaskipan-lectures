#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *link;
};

typedef Node* NodePtr;

class IntList
{
    private:
        NodePtr head;

    public:
        void head_insert(int item) {
            NodePtr tmp_ptr;
            tmp_ptr = new Node;
            tmp_ptr->item = item;
            tmp_ptr->link = head;
            head = tmp_ptr;
        }

        void print() {
            cout << "List: " << endl;
            if(head == NULL) {
                cout << "<empty>" << endl;
            }

            for(NodePtr iter = head; iter != NULL; iter = iter->link) {
                cout << iter->item << endl;
            }
        }

        NodePtr search(int target) {
            NodePtr iter;
            for(iter = head; iter != NULL; iter = iter->link) {
                if(iter-> item == target) {
                    return iter;
                }
            }
            return NULL;
        }

        void insert(NodePtr after_me, int item) {
            NodePtr tmp_ptr;
            tmp_ptr = new Node;
            tmp_ptr->item = item;

            tmp_ptr->link = after_me->link;
            after_me->link = tmp_ptr;
        }

        void head_remove() {
            if(head == NULL) {
                return;
            }

            NodePtr old_head = head;
            head = head->link;

            delete old_head;
        }
};

int main() {
    IntList lis;

    for(int i = 0; i != 10; i++) {
        lis.head_insert(i*i);
    }

    lis.print();
    NodePtr result;
    result = lis.search(81);
    lis.insert(result, 35);
    lis.print();
    lis.insert(lis.search(0), 42);
    lis.print();
    for(int i = 0; i != 3; i++) {
        lis.head_remove();
    }
    lis.print();
}

