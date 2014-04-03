#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Node.h"
#include "ListException.h"

using namespace std;

class List
{
	public:
		List();
		~List();
		// Constructor: creates an empty list
		// Destructor: removes all nodes in the list
		NodePtr minNode() throw (ListException);
		// Returns the node with the minimum element in the list.
		Throws an exception if the list is empty,
			   NodePtr getHead(); // Returns a pointer to the head node
		void insert(NodePtr after_me, NodePtr new_node) throw
			(ListException);
		// Inserts a new node after the node after_me. If after_me
		is NULL, then it is assumed that the list is empty. Throws an
			exception if the new node is NULL
			void remove(NodePtr before) throw (ListException);
		// Removes the node coming after the node named before.
		// Throws an exception if before is NULL or if the node to be
		deleted is NULL
			friend ostream& operator <<(ostream& outs, const List& lis);
		// A friend function for writing the contents of the list to
		an output stream
	private:
			NodePtr head; // pointer to the head of the list
};

#endif // LIST_H
