#include <iostream>
using namespace std;

NodePtr createNode(int the_number) {
// Creates a new node with value the_number
// Both links are initialised to NULL
// A pointer to the new node is returned

    // You have to program the body of this function
}

void display(NodePtr head) {
// displays the contents of the list pointed to by head on the screen

     // You have to program the body of this function
}

void displayReverse(NodePtr head) {
// displays the contents of the list pointed to by head on the screen in a reverse order

    // You have to program the body of this function
}

void insert(NodePtr& after_me, NodePtr& newNode)
// after_me is a pointer to the node after which newNode will be inserted
{
    // You have to program the body of this function
}


void remove(NodePtr& head, NodePtr discard) {
// head is a pointer to the head of the list
// discard is a pointer to the node to remove
    // Then we are discarding the first node
    if (discard->back_link == NULL) {
        // Now the head pointer points to the node after discard (could be NULL)
        head = discard->forward_link;
        // If the head is not NULL, then make sure that its back link is set to NULL
        if (head != NULL) {
            head->back_link = NULL;
        }
    }
    else {
        // Make the node preceeding the discard node point forward to the node coming after discard
        (discard->back_link)->forward_link = discard->forward_link;
        if (discard->forward_link != NULL) {
            // Make the node coming after discard point back to the node preceeding discard
            (discard->forward_link)->back_link = discard->back_link;
        }
    }
    delete discard;    // Now we can safely delete discard
}


int main() {
    NodePtr head, nodePtr1, nodePtr2, nodePtr3;

    head = NULL;    // Initially, the list is empty

    nodePtr1 = createNode(1);   // NodePtr1 points to a new node with data=1
    insert(head, nodePtr1);     // Insert that node after NULL, i.e. into an empty list
    nodePtr2 = createNode(2);   // NodePtr2 points to a new node with data=2
    insert(head, nodePtr2);     // Insert that node after the head node
    nodePtr3 = createNode(3);   // NodePtr3 points to a new node with data=3
    insert(head->forward_link, nodePtr3); // Insert that node after the second node

    display(head);              // Display the nodes of the list
    displayReverse(head);       // Display the nodes in a reverse order

    remove(head, nodePtr2);     // Remove the second node
    display(head);
    displayReverse(head);

    remove(head, nodePtr1);     // Remove the first node
    display(head);
    displayReverse(head);

    remove(head, nodePtr3);     // Remove the first node (which originally was the third node)
    display(head);
    displayReverse(head);

    return 0;
}
