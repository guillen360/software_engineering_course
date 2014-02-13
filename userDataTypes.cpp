#include <iostream>

/*
STRUCTS!  user define data types

*/
struct Point {
	int x;
	int y;
};

void print_point(Point p)
{
	std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
}

void userDataTypes()
{
	Point p;
	p.x = 1;
	p.y = 2;
	print_point(p);

	Point *ptr;
	ptr = &p;
	print_point(*ptr); // equivalen to print_point(p) because *ptr = p
	// alternative to do de-reference a pointer:
	std::cout << "(" << ptr->x << "," << ptr->y << ")" << std::endl;

}