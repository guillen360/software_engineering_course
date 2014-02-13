
/*
Recursion:
=========
running a methodology repeatedly 
AND it calls itself:
****************
find()
.... 
	find();
****************

Principles:
==========
- need a base case
	-> a terminator, to stop the loop


*/

int factorial (int n)
{
/*
Factorial: ex: 4! -> 4 x 3 x 2 x 1 = 24
	n! -> n(n-1)!(n-2)!(...)!(1)

base cases:
1) gt or eq to 0
2) 
*/
	// case 1:
	if (n<0) return -1;
	if (n ==0) return 1;
	if (n==1) return 1;

	return n * factorial(n-1);

}