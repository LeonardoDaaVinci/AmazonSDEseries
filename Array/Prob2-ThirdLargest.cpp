Third Largest:
	Find the third largest number from the given array.

Required Functions to solve this:
	The solution for this problem has two important modules to it.
	1.  We need to use qsort function from stdlib.
		Following is the syntax to use it.
		void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
	2. 	We need to create the compare function to use the above sort function.
	
Solution:
	1. Send the input array which needs to sorted.
	2. Once the input array is sorted in descending order. Return the third largest digit by arr[0]
	
Code:
int cmp(const void* a, const void* b)
{
	const int* first = (const int*)a;
	const int* second = (const int*)b;
	return *first < *second;
}

int thirdLargest(int *a, int n)
{
	//Your code here
	if (n <= 2)
		return -1;
	qsort((void*)a, n, sizeof(int), cmp);
	return a[2];
}