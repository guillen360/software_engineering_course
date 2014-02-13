#include <iostream>

void arrays()
{
	 /* 
	 - in c++, memory is assigned but NOT initialized so this will display something 
	 - the compiler does not do a bound check!

	 */

	// define an array:
	int my_array[4];

	// array elements are 0 based.
	std::cout << "first element: " << my_array[0] << std::endl;

	//here is an assignment:
	my_array[0] = 1;

	// display value (note: occ 1 and 2 have not been initialized so they have some arbitrary value):
	for (int i=0; i<3; i++)
	{
		std::cout << i << "->" << my_array[i] << std::endl;
	}
	
}