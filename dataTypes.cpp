/*
Built-in types (our primitives)
==============
bool 
- 1 bit 
- [0,1]
	-- but because the way computers work, it's easier to move 
	   around 8 bits so it's really stored in 8 bits (for speed)
char 
- 8 bits (1 byte)
- [0, 255]
- in ascii table, the 256 printable characters in the Western world

int
- 32 bits (4 bytes) *most of the time
- range: [-2^31, 2^31 -1] 
	- what influences int value size?
		-- depends on computer architecture (32 bit vs 64 bit)
		-- depends on compiler (*C++ is fun?)

float
- 32 bits (4 bytes)
- 7 digits of precision
-- not as much precision as int?

double
- 64 bits (8 bytes)
- 2x memory and 2x precision as float

void
- you'll see this for function to indicate nothing is returned


Storing data
============
- hard drive 
- RAM
- DVDs

Binary
=====
-string of 0s & 1s 
- one instance is called a "bit"
- multiple bit is a byte (8 bits)

*/

#include <iostream>

using namespace std;

void dataType()
{
	bool my_bool = true;
	char my_char = 'd';
	int my_int;
	float my_float;
	double my_double;

	my_int = 11;
	my_float = 12.3f;
	my_double = 3.14;

	// if you include the namespace std, don't need to type std::cout BUT instead:
	cout << "my_bool = " << my_bool << endl;
	cout << "my_char = " << my_char << endl;
	cout << "my_int = " << my_int << endl;
	cout << "my_float = " << my_float << endl;
	cout << "my_double = " << my_double << endl;

	// basic operators (addition, subtraction,multiplication, division):
	cout << "4 + my_int = " << 4 + my_int << endl;
	cout << "my_int / 2 = " << my_int / 2 << endl;
	//  two ways to fix the truncation issue:
	cout << "my_int / 2.0 = " << my_int / 2.0 << endl; // --> let compiler use the best type
	// --> casting????

	cout << "my_float * my_double = " << my_float * my_double << endl;

}