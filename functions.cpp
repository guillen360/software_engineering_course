#include <iostream>
 
#include "simple_math.h"

int functions()
{
	/*
	EX:
	<return type> <name> (<parameters>, ...){
		<statements>
	}

	*/
	int x, y;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> x >> y;

	int sum = add(x,y);

	std::cout << "the sum of " << x << " and " << y << " is " << sum << std::endl;

	return 0;
}