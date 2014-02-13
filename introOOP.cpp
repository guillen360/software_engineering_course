#include <iostream>

void introOOP()
{
/*

Object Oriented Programming (OO or OOP) groups
the data and the functions together

CLASS:
=====
- layout of the data and the functions ("blueprint")
--> Members:
    =======
	- individual elements of a class
	- Fields -> Data
	- functions -> Behaviours / Methods

Objects:
=======
- instantiations of a class

Implementation:
==============
- classes look similar to a struct:

class List 
{
	List *head;
}
-> structs are actually synonymous to a class. class has the 
added advantage of "access level/protection"
*** structs are public by default!

-- classes allow you to obfuscate implementation details:
classes have three levels:
public -> everyone has acess
private -> only memeber functions have access (default)
protected -> affects the visibility of inheritance

examples:
class List 
{
	public: 
		[ statements ]
	private:
		[ statements ]
	public:
		[ statements ]
};

SO.... these two are the same:
1)
struct List
{
	List *head;
};

2)
class List 
{
	public:
		List *head;
};
*/
}