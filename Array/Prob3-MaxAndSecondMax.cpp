Max and Second Max:
	Given an array arr[] of size N of positive integers which may have duplicates. 
	The task is to find the maximum and second maximum from the array, and both of them should
	be distinct, so If no second max exists, then the second max will be -1.

Solution:
	1. Iterate throught the whole array updating the max and second max.
	2. First initialize the max as first element and max2 as -1;
	3. Then start iterating through the array. If we find an element greater than current max. Make that 
		as the new max. Replace max2 with old max as we know till this point that was the highest. ( IF LOOP)
	4. There will also be a case, where the current iterated element is not greater than max but larger than
		the current max2. If so, update it accordingly( ELSE LOOP )
	
Solution:
	1. Send the input array which needs to sorted.
	2. Once the input array is sorted in descending order. Return the third largest digit by arr[0]
	

Code:
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]) {
	vector<int> res;
	int max = arr[0], max2 = INT_MIN;
	for (int i = 0; i<sizeOfArray; i++)
	{
		if (arr[i]>max)
		{
			max2 = max;
			max = arr[i];
		}
		else if (arr[i] > max2 & arr[i]<max)
		{
			max2 = arr[i];
		}
	}
	res.push_back(max);
	if (max2 == INT_MIN)
		max2 = -1;
	res.push_back(max2);
	return res;

}