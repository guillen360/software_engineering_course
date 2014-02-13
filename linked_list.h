#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class LinkedList 
{
public:
	LinkedList();  // this is called a "default constructor" or ctor
	virtual ~LinkedList(); // this is how you define a destructor
				   // (1) use ~ (2) no parameters are passed
				   // (3) use 'virtual' to prevent memory leaks from inheriting objects
public:
	void push_front(int val);
	void push_back(int val);
	void remove(int val);
	int remove_back();
	void print();

	class Node
	{
	public:
		int value;
		Node *next; 
	};
protected:  // we are changing this from "private" to "protected" so it can be used by inhereting objects
	Node *head;
};

#endif