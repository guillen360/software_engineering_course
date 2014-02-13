#include "linked_list.h"

#ifndef _STACK_H_

#define _STACK_H_

class Stack : protected LinkedList
{
public:
	Stack() { } // scoping out constructor here in header file
				// because we won't actually use it in the cpp 
				// file
	~Stack() { }
public:
	void push(int val);
	int pop();
	int peek();
	void print() { static_cast<LinkedList*>(this)->print(); }
};

#endif