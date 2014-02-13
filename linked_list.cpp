#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList()
{
	this->head = 0; // can also use NULL if you import the header files
}
LinkedList::~LinkedList()
{
	Node *current_Node = this->head;
	while (current_Node != 0)
	{
		Node *next_Node = current_Node->next;
		delete current_Node;
		current_Node = next_Node;
	}
}
void LinkedList::push_front(int val)
{
	if (head == 0) 
	{
		this->head = new Node;
		this->head->next = 0;
		this->head->value = val;
	} 
	else 
	{
		Node *n = new Node;
		n->value = val;
		n->next = head;
		this->head = n;
	}
}
void LinkedList::push_back(int val)
{
	if (this->head == 0) 
	{
		this->head = new Node;
		this->head->next = 0;
		this->head->value = val;
	} else {
		// traverse the list looking for last item...
		Node *current_Node = this->head;
		while (current_Node->next != 0)
		{
			current_Node = current_Node->next;
		}
		// we have the last item in 'current', create new one:
		current_Node->next = new Node;
		current_Node->next->value = val;
		current_Node->next->next = 0;
	}
}
void LinkedList::remove(int val)
{
	if (this->head == 0) return;

	Node *current_Node = this->head;

	// special case for first item
	if (current_Node->value == val)
	{
		// need to delete this and update list->head to point to the next pointer on the one we are deleting
		this->head = current_Node->next;
		delete current_Node;
	} 
	else 
	{
		Node *previous_Node = current_Node;
		// loop through all nodes looking for value:
		while (current_Node != 0)
		{
			if(current_Node->value == val)
			{
				previous_Node->next = current_Node->next;
				delete current_Node;

				return;
			}
			else
			{
				previous_Node = current_Node;
				current_Node = current_Node->next;
			}
		}
	}
}
int LinkedList::remove_back()
{
	if (this->head == 0) return INT_MIN;

	Node *current = head;
	Node *previous = 0;  // init a value!
	while (current->next != 0)
	{
		previous = current;
		current = current->next;
	}

	int return_value = current->value;

	// special case:
	if (current == head)
	{
		head = 0;
		delete current;
	}
	else
	{
		previous->next = 0;
		delete current;
	}
	
	return return_value;
}
void LinkedList::print()
{
	for (Node *next = this->head; next != 0; next = next->next)
	{
		std::cout << "node value is "<< next->value <<std::endl;
	}
}