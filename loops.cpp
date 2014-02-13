#include <iostream>

void loops()
{
	/*
	shorthand for incrementing:
	+=
	-=
	*=
	/=

	*/

	// FOR loop:  for (initial; condition; increment) { statement }
	std::cout << "a standard FOR loop;" << std::endl;
	int limit = 5;
	for (int i=0; i<limit;i++)
	{
		std::cout<< i;
		if (i < limit - 1)   //  notice that for an if statement with a single statement, curly braces not req
			std::cout << ", ";
	}
	std:: cout << std::endl;

	// WHILE loop: while (condition) { statements }
	std::cout << "a standard WHILE loop;" << std::endl;
	int i = 0;
	int w_limit = 5;
	while (i < w_limit) {
		std::cout << i;
		if (i < w_limit - 1){
			std::cout << ", ";
		}
		i++;
	}
	std::cout << std::endl;

	// DO WHILE loop:
	std::cout << "a standard DO-WHILE loop;" << std::endl;
	int j = 0;
	int d_limit = 5;
	do {
		std::cout << j;
		if (j < d_limit - 1){
			std::cout << ", ";
		}
		j++;
	} while (j < d_limit);

	std::cout << std::endl;
}