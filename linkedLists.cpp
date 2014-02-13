#include <iostream>

/*
want to solve a real problem:
store arbitrary number of items

an array?
- but it's fixed size
- it is contigious (a whole block)

a pointer?
- links together different areas of memory

a struct? 
- with values and pointers???

*/
struct Node
{
	int value;
	Node *next;
};

void print_list(Node *list) // pointer is more efficient than actual struct
{
	// error checking:
	if (list == NULL) return;

	// we have to assume the pointer is initialized

	for (Node *next = list; next != NULL; next = (*next).next)
	{
		std::cout << "node value is "<< (*next).value <<std::endl;
	}
};

void linkedList()
{
	// first list node:
	Node list;
	list.value = 100;
	list.next = NULL;

	Node another_list;
	another_list.value = 200;
	another_list.next = NULL;
	list.next = &another_list;

	print_list(&list);
}
