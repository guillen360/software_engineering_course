#include "stack.h"

void Stack::push(int val)
{
	push_back(val);
}

int Stack::pop()
{
	return remove_back();
}

int Stack::peek()
{
	// for educational purpose, we are going to implement it 
	// here...
	Node *current = head;
	while (current->next != 0)
	{
		current = current->next;
	}
	return current->value;
}