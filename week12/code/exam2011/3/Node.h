#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node(int value, Node *next) : data(value), link(next) {};
		// Constructs a node with a value and next link
		int getData() const {return data;};
		// Retrieves the value for this node
		Node* getLink() const {return link;};
		// Retrieves the next node in the list
		void setData(int value) {data=value;};
		// Modifies the value stored in the list
		void setLink(Node* next) {link=next;};
		// Changes the reference to the next node
	private:
		int data;
		Node *link;
};

typedef Node* NodePtr;

#endif // NODE_H

