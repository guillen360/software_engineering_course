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

behaviour our linked list needs:
- init state (init)
- add a node (push)
- remove linked list from memory (cleanup)
- delete a node

*/
struct More_Node
{
	int value;
	More_Node *next;
};
struct List 
{
	More_Node *head;
};

void list_init(List *list)
{
	if (list == NULL) return;

	list->head = NULL;
}

void list_insert(List *list, int val)
{
	if (list == NULL) return;

	if (list->head == NULL) 
	{
	list->head = new More_Node;
	list->head->next = NULL;
	list->head->value = val;
	} 
	else 
	{
		More_Node *n = new More_Node;
		n->value = val;
		n->next = list->head;
		list->head = n;
	}
}

void list_push(List *list, int val)
{
	if (list == NULL) return;

	if (list->head == NULL) 
	{
		list->head = new More_Node;
		list->head->next = NULL;
		list->head->value = val;
	} else {
		// traverse the list looking for last item...
		More_Node *current = list->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		// we have the last item in 'current', create new one:
		current->next = new More_Node;
		current->next->value = val;
		current->next->next = NULL;
	}
}

void list_delete(List *list, int val)
{
	// steps:
	// 1) find if val exists
	// 2) duplicates? we are going to delete the first one we find
	// 3) remove the block of memory with val
	// 4)
	// 3) update pointer
	if (list == NULL) return;
	if (list->head == NULL) return;

	More_Node *current = list->head;

	// special case for first item
	if (current->value == val)
	{
		// need to delete this and update list->head to point to the next pointer on the one we are deleting
		list->head = current->next;
		delete current;
	} 
	else 
	{
		More_Node *previous = current;
		// loop through all nodes looking for value:
		while (current != NULL)
		{
			if(current->value == val)
			{
				previous->next = current->next;
				delete current;

				return;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
}

void list_cleanup(List *list)
{
	if (list == NULL) return;

	More_Node *current = list->head;
	while (current != NULL)
	{
		More_Node *next = current->next;
		delete current;
		current = next;
	}
}

void list_print(List *list) // pointer is more efficient than actual struct
{
	// error checking:
	if (list == NULL) return;

	// we have to assume the pointer is initialized

	for (More_Node *next = list->head; next != NULL; next = next->next)
	{
		std::cout << "node value is "<< next->value <<std::endl;
	}
};

void ll_main()
{
	std::cout << "List list;" << std::endl;
	List list;
	std::cout << "list_init" << std::endl;
	list_init(&list);

	std::cout << "list_push" << std::endl;
	int val = 1;
	while (val < 10)
	{
		list_push(&list, val);
		val++;
	}
	
	std::cout << "list_print" << std::endl;
	list_print(&list);
	
	std::cout << "list_delete" << std::endl;
	val = 3;
	while (val < 7)
	{
		list_delete(&list, val);
		val++;
	}
	
	// delete something not on the list:
	list_delete(&list, 20);

	std::cout << "list_insert" << std::endl;
	list_insert(&list, 23);
	list_print(&list);


	std::cout << "list_delete" << std::endl;
	list_delete(&list, 23);
	list_print(&list);

	std::cout << "list_print" << std::endl;
	list_print(&list);

	std::cout << "list_cleanup" << std::endl;
	list_cleanup(&list);

}
