#include <iostream>
#include "linked_list.h"

void main_linkedListOOP()
{
	std::cout << "--> main_linkedListOOP" << std::endl;

	// test DRIVE of linked list: 
	LinkedList list;  
	 
	int val = 1;
	while (val < 10)
	{
		list.push_back(val);
		val++;
	}
	 
	list.print();
	 
	val = 3;
	while (val < 7)
	{
		list.remove(val);
		val++;
	}
	
	// delete something not on the list:
	list.remove(20);
	 
	list.push_front(23);
	list.print();

	 
	list.remove(23);
	list.print();

	// doesn't need a cleanup.. destructor handles it!
}