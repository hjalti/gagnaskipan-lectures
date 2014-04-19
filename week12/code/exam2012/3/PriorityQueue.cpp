#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    front = back = NULL;
}

PriorityQueue::~PriorityQueue()
{
    while(!empty()) {
        remove();
    }
}

void PriorityQueue::add(string theItem)
{
    add(theItem, 0);
}

void PriorityQueue::add(string theItem, int thePriority)
{    if(empty()) {
        addToEmptyQueue(theItem, thePriority);
    } else {
        NodePtr new_node = new QueueNode;
        new_node->priority = thePriority;
        new_node->data = theItem;
        new_node->link = NULL;

        NodePtr prev = NULL;
        for(NodePtr it = front; it != NULL; prev = it, it = it->link) {
            if(it->priority < thePriority) {
                if(prev == NULL) {
                    front = new_node;
                } else {
                    prev->link = new_node;
                }
                new_node->link = it;
                return;
            }
        }
        prev->link = new_node;
        back = new_node;
    }
}

string PriorityQueue::remove()
{
    if(empty()) {
        throw QueueException(":'(");
    }
    string res = front->data;
    NodePtr next = front->link;
    delete front;
    front = next;
    if(front == NULL) {
        back = NULL;
    }
    return res;
}

bool PriorityQueue::empty() const
{
    return (front == NULL);
}

void PriorityQueue::addToEmptyQueue(string theItem, int thePriority)
{
    front = new QueueNode;
    front->data = theItem;
    front->priority = thePriority;
    front->link = NULL;
    back = front;
}
