#include <iostream>

void cStyleString()
{
	/*
	string: "hello\0"  
		- strings are null terminated with "\n"

		takesaways-- DO NOT OVERFLOW YOUR BUFFER:
		always use strncpy and cin.getline
	*/
	char *myString = "Hello World\0";
	std::cout << myString << std::endl;

	// first issue with strings: allocating memory..
	// allow strcpy do the work:
	char buffer[10];
	strcpy(buffer, "hello");  // null character handled for us..
	std::cout << buffer << std::endl;

	// strncpy makes sure we copy the right about of characters:
	char another_buffer[10];
	strncpy(another_buffer, "hello crazy world", 9);  // 9 so that null terminator is included
	std::cout << another_buffer << std::endl;

	// avoiding memory leaks when accepting user input:
	char some_buffer[10];
	std::cout << "what is your name?" << std::endl;
	// BAD!!!
	//std::cin >> some_buffer;
	std::cout << "some_buffer = " << some_buffer << std::endl;

	// do it this way:
	char good_buffer[10];
	char str[10];
	std::cout << "what is your name again?" << std::endl;
	std::cin.getline(good_buffer, 10);
	strncpy(str, good_buffer, 9);
	std::cout << "hello " << good_buffer << std::endl;
	std::cout << "hello(2) " << good_buffer << std::endl;
}