#include <iostream>

// this is the header file for functions for 3dBuzz training 
// cpp files:
#include "3dBuzztraining.h"

// header file for all functions from C++ Cookbook
#include "CppCookbook.h"

int main(int argc, char * const argv[])
{
	char const *debug_msg = "**** TESTING SCRIPT: main.cpp ****";
	for (int i=0; i < strlen(debug_msg); i++)
	{
		std::cout << debug_msg[i];
	}
	std::cout << std::endl;

	// *************************************************
	// *************************************************
	// *************************************************
	// START...
	// *************************************************
	int a[] = {100, 1,3,7,9,4,0,23, 89, 5,6,2,8, 51, 60, 40, 39};//{10,9,8,7,6,5,4,3,2,1,0};//{100, 1,3,7,9,4,0,23, 89, 5,6,2,8, 51, 60, 40, 39};
	int len = sizeof(a) / sizeof(a[0]);
	
	tree__main();
	
	// *************************************************
	// END
	// *************************************************
	// *************************************************
	// *************************************************

	return 0;
}