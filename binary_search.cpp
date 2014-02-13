
#include <iostream>

int find(int *arr, int start, int end, int item)
{
/*
this is a binary search algorithm
written as a recursive function

 returns the int index value of where the item
 is found

*/
	// terminator--> item not found:
	if ((start > end) || (end < start))
	{
		return -1; // item NOT found
	}
	// base case:
	int index = (start + end) / 2;
	if ( arr[index] == item)
	{
		return index;
	}
	// array not found, create new start and end:
	int new_start, new_end;
	if (item > arr[index])
	{
		new_start = index + 1;
		new_end = end;
	} 
	else // item < arr[index]
	{
		new_start = start;
		new_end = index - 1;
	}
	
	return find(arr, new_start, new_end, item);
}