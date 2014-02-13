/*
PROJECT EULER # 6:
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/
int sumSqr(int n)
{
	if (n <=0 ) return 0;
	if (n == 1 ) return 1;

	return (n * n) + sumSqr(n-1);
}
int sqrSums(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum * sum
	;
}