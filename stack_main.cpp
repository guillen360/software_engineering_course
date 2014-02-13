#include <iostream>
#include "stack.h"

void stack_main()
{
	std::cout << "testing stack implementation" << std::endl;

	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.print();

	std::cout << "pop: " << (int)stack.pop() << std::endl;

	stack.print();

	stack.push(4);
	stack.push(5);

	stack.print();

	std::cout << "peek: " << (int)stack.peek() << std::endl;

	stack.print();

	std::cout << "pop: " << (int)stack.pop() << std::endl;
	std::cout << "pop: " << (int)stack.pop() << std::endl;
	std::cout << "pop: " << (int)stack.pop() << std::endl;

	stack.print();

}