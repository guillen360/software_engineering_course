#include <iostream>

void dynamic_memory()
{
	double *ptr = new double; // this is being allocated in the heap (it is using the "new" keyword)!

	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;

	*ptr = 44;

	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;

	// reclaim memory on heap:
	delete ptr;


	// WHAT ABOUT AN ARRAY???
	int length;
	std::cout << "please enter the desired array length...";
	std::cin >> length;

	double *a_ptr = new double[length];
	*a_ptr = length * length; // init first occurrence

	// load values:
	for (int i = 1; i < length; i++)
	{
		*(a_ptr + i) = 1 + *(a_ptr + (i-1));
	}
	// display results:
	int i = 0;
	for (int i = 0; i < length; i++, a_ptr++)
	{
		std::cout << i << " -> " << *a_ptr << "(" << a_ptr << ")" <<std::endl; 
	}
	// which one am I on?
	std::cout << *a_ptr << "(" << a_ptr << ") ** some unallocated space... it was incremented within for loop above" <<std::endl; 

	// let's get back to the beginning:
	std::cout << sizeof(a_ptr) << std::endl; // each occurrence is 4 bytes so..
	// back to my last occurrence:
	a_ptr--;
	std::cout << *a_ptr << "(" << a_ptr << ") ** last allocated occurrence" <<std::endl;

	// now to the beginning:
	a_ptr = a_ptr - (length - 1); // length - 1 because it is offset by 0
	std::cout << *a_ptr << "(" << a_ptr << ") ** beginning of the array" <<std::endl;

	// reclaim memory:
	// delete [] a_ptr; // need the [] for an array


}