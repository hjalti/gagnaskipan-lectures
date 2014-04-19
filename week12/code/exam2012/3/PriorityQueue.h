//This is the interface for the class PriorityQueue, which is a class for a
//queue of strings where each string is associated with a priority.
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <string>
#include "QueueException.h"

using namespace std;

struct QueueNode
{
	string data;
	int priority;
	QueueNode *link;
};

typedef QueueNode* NodePtr;

class PriorityQueue
{
	public:
		PriorityQueue();
		// A constructor: Initializes the object to an empty priority queue.
		~PriorityQueue();
		// A destructor
		void add(string theItem);
		//Postcondition: theItem has been added to the back of the priority
		//queue with priority 0. Uses addToEmptyQueue()
		void add(string theItem, int thePriority);
		//Postcondition: theItem has been added to the correct position in the
		//priority queue based on the thePriority.  Uses addToEmptyQueue().  If
		//the new item to be added has priority >= the priority of an existing
		//item then the new item is inserted before the existing item
		string remove();
		//Returns and removes the item at the front of the priority queue and throws an
		//instance of QueueException if the priority queue is empty
		bool empty( ) const;
		//Returns true if the priority queue is empty. Returns false otherwise.
	private:
		NodePtr front;
		//Points to the head of a linked list. Items are removed at the head
		NodePtr back;
		//Points to the back of a linked list. Items are inserted at the back
		//if no priority is given.
		void addToEmptyQueue(string theItem, int thePriority);
};
#endif //PRIORITYQUEUE_H
