#include <iostream>

void pointers()
{
/*
an oversimplification of memory management in c++:
there's the heap and they stack
stack
=====
all static content, like the variables I declare or
functions i prototype

heap
====
all the dynamic content. for notably, arrays:
int x = 10;
int *int_array[x]
-----> technically, the compiler does not know at runtime
what size to make the above array so the above will cause a compile
error.  instead, we do the following:
int x = 10;
int *int_array = new int[x]
then when we are done with array:
delete [] int_array;

to free up the heap memory space (it has been allocated 
and not available so long as my program is running)

Pointers
========
int *int_p; --> 4 bytes (32 bits)
decimal  *dec_p; --> 4 bytes (32 bits)
char *char_p; --> 4 bytes (32 bits)

*/
	int *ptr;  // same as "int* ptr;" or "int * ptr;
	int x = 255;
	
	ptr = &x;
	
	std::cout << "x = " << x << std::endl;
	std::cout << "&x = " << &x << std::endl;
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "display the actual value of the memory location (aka pointer):" << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;
	
}