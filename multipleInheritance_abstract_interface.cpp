#include <iostream>
/*
ABSTRACT CLASS
==============
the concept is that the class 
CANNOT be instantiated
compiler will generate an error

used to provide a base implementation of a function
but don't want the client to create a instance of it

you mark a method as "pure virtual" you add the following:
= 0;

INTERFACE
=========
from a software engineering point of view, 
they don't exist.

It's really nothing more than an abstract class
an interface,however, contains absolutely NO DATA!
method signatures ONLY.

think of an interface as a contract.

useful for the following:
allows you to code to an interface instead of 
an implementation (good design principle)
client can implement to the higher level 
interface and not need to know the details about
implementation

Multiple inheritance
====================
deriving from multiple classes

*/

class Character 
{
public:
	virtual void Talk() = 0; // FOR ABSTRACT - only one virtual method needs to be marked pure virtual (= 0)
private:
	int health; // C++ allows you to define a variable in abstract class
};

class Mage : Character
{
public:
	virtual void Talk() { std::cout << "Mage rules" << std::endl; }
	virtual void doDamage() {std::cout << "damage" << std::endl;}
};

class Priest : public Character 
{
public:
	virtual void Talk() { std::cout << "priests rules" << std::endl; }
	virtual void doHeals() {std::cout << "heals" << std::endl;}
};

class Shaman : public Mage, public Priest
{
public:
	virtual void Talk() { std::cout << "shaman rules" << std::endl; }
private:

};


void multipleInheritance_abstract_interfaces()
{
	std::cout << "*TESTING-> multiple_inheritance();" << std::endl;

	// cannot do the following 
	//Character test;
	Mage bob;
	Priest henry;
	Shaman frankie;

	bob.Talk();
	bob.doDamage();

	henry.Talk();
	henry.doHeals();

	// ambigious if Shaman does implement a talk method:
	frankie.Talk();
	frankie.doDamage();
	frankie.doHeals();

}