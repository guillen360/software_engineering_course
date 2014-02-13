void bubbleSort(int *arr, int arr_len)
 {
/*
one of the more inefficient algorithms.

descriptions:
keep looping through the entire array pushing the largest
value to the end of the array until the array is sorted

performance:
O(n**2) --> this algorithm grows exponentially as the array size increases

*/
	 bool swap_performed = false;
	 int next = 0;
	 int temp;
	 int upper_bound = arr_len;
	 do
	 {
		 // terminator:
		swap_performed = false;
		for (int i = 0; i < upper_bound-1; i++)
		{
			next = i + 1;
			if (arr[i] > arr[next])
			{
				// swap:
				temp = arr[next];
				arr[next] = arr[i];
				arr[i] = temp;
				swap_performed = true;
			}
		}
		upper_bound--;
	 } while (swap_performed);
 }

void selectionSort(int *arr, int arr_len)
{
/*
like bubbleSort, pretty inefficient for an array (technically, more inefficient
because bubble sorts will terminate sooner).  
the benefit of is that depending on the 
data structure, selection sort can be a very efficient method to sort a data
structure.

descriptions: you want to loop through each occurrence in the array
and find the smallest value from that occurrence to the end of the array

performance:
O(n**2) --> this algorithm grows exponentially as the array size increases

selection sort is kind of like a bubble sort in reverse...
*/
	int temp;
	for (int i = 0; i < arr_len-1; i++) // don't need to run for the last occurrence so can do i < arr_len-1 
	{
		for (int j = i + 1; j < arr_len; j++)
		{
			if (arr[i] > arr[j])
			{
				// perform swap ** instead of doing the swap in place, i can hold on the 
				// the index value and swap at the conclusion of the for loop
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertionSort(int *arr, int arr_len)
{
/* 
combines some of the features of a selection and bubble sort but
for small data structures and for those arrays that are almost in order,
this sort is more efficient

descriptions:
walk through the "unsorted" segment of array and "insert"
the unsorted value into the sorted side
*/
	int j;
	int temp;
	for (int i = 1; i < arr_len; i++) // start at 1 .. 0 is the sorted side
	{
		j = i;
		while ((j > 0) && (arr[j - 1] > arr[j]))
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

void merge(int *arr, int start, int mid, int end)
{
	// 'static' allows the array to be shared
	static int temp_array[100]; // = new int[end]; // is this (dynamically allocatting memory) the best way of doing this?

	int left_start = start;
	int left_end = mid;
	int right_start = mid + 1;
	int right_end = end;

	// walk both sides and compares values:
	int index = left_start;
	for (; left_start <= left_end && right_start <= right_end; ++index)
	{
		if (arr[left_start] < arr[right_start])
		{
			temp_array[index] = arr[left_start];
			left_start++;
		} else
		{
			temp_array[index] = arr[right_start];
			right_start++;
		}
	}

	// fill in remaining left side:
	for (; left_start <= left_end; ++left_start, ++index)
	{
		temp_array[index] = arr[left_start];
	}

	// fill in remaining right side:
	for (; right_start <= right_end; ++right_start, ++index)
	{
		temp_array[index] = arr[right_start];
	}

	// our temp_array is sorted. let's move it to arr:
	for (int i = start; i <= end; i++)
	{
		arr[i] = temp_array[i];
	}

	//delete temp_array;
}
void mergeSort(int *arr, int start, int end)
{
/*
merge sort is the fastest one you could use but it does take more memory
than the other ones we've been using (uses a temporary space)
- great for sorting data on a disk (where you can queue data from some source)
OR when sorting copiouos amounts of data

performance:
O(N x logN)

descriptions:
chops the array in two and then combines them (can it be use for a linked list? probably not)

*/
	// recursive functions need a terminator:
	if (start >= end) return;
	
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid); // left
	mergeSort(arr, mid + 1, end); // right

	merge(arr, start, mid, end); 
	
}

void quickSort(int *arr, int start, int end) // start and end is BY INDEX VALUE!
{
/*
- is quick! (surprise)
- it can sort in place
- runs O * logN so it's very fast!
- works efficiently when everything is stored in memory already

description:
- using a "pivot" value, you can collect all the data on greater than 
pivot value to the right side and all the data less than the pivot value
to the left side of the array
how does one choose pivot value?
it's arbitrary, as long as it is in the range of the values of the array

*/
	// recursive loop terminator
	if (start == end) return;

	int left = start;
	int right = end;
	int pivot = arr[left]; // this is arbitrary

	while (left < right) // no overlap
	{
		// increment left side counter while less than
		// arbitrarily chosen "pivot" value:
		for (; arr[left] < pivot; left++);
		// decrement right side counter while greater
		// arbitrarily chosen "pivot" value:
		for (; arr[right] > pivot; right--);

		// we have a right and left counter values:
		if (left < right)
		{
			// swap:
			int temp = arr[left];
			arr[left]  = arr[right];
			arr[right] = temp;
			// increment/decrement left and right counters for next iteration:
			left++;
			right--;
		}
	}
	if (left == right) left++;

	quickSort(arr, start, right);
	quickSort(arr, left, end);

}