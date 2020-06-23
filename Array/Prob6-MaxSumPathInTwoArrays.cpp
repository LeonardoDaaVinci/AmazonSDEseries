Maximum Sum Path In Two Arrays :
	Given two sorted arrays A and B, such that the arrays may have some common elements. Find the sum of the
	maximum sum path to reach from the beginning of any array to end of any of the two arrays.
	We can switch from one array to another array only at the common elements. 

Solution:

Requirements:

	1. Create iterators aIter and bIter for the traversing arrays A and B respectively.
	2. Create two variable aSum and bSum which remembers the sum till the current position between common elements.
	3. Create maxSum variable which will store the maximum Sum path and will be result.

Approach:
	1. Iterate both the arrays in following ways untill any one of the iterator reaches one position after the end.
		a. If element at aIter position < bIter position, update the aSum by adding that element value 
			to it and move the iterator to the next position in the array A. No change in bIter position.
			
		b. If element at aIter position > bIter position, update the bSum by adding that element value 
			to it and move the iterator to the next position in the array B. No change in aIter position.

		c. If the element at aIter position = bIter position, find whose sum is maximum till this position.
		  Is it that of aSum or bSum.? Update the maxSum by adding that to the maxSum. We need to refresh
		  aSum and bSum value to zero.
		  We need to do this refresh aSum and bSum value's scope is only between common elements as defined in requirements.
		  The knowledge before that has already been tranferred to the maxSum variable.
		  
	2. If one among the iterators has reached the end of the array. We have its corresoponding sum cached untill that position and
		beyond the common element as aSum or bSum.
	
	3. Now iterate throught the array that hasn't reached the end. Find the sum corresponding to that array when the iterator is at
		end. Now compare if aSum is greater or bSum is greater.
		Add the maximum value to the global maxSum.
	
	
CODE
//
int max_path_sum(int A[], int B[], int l1, int l2)
{

	int aSum = 0;
	int bSum = 0;
	int maxSum = 0;
	int aIter = 0;
	int bIter = 0;

	while (aIter != l1 && bIter != l2 )
	{
		if (A[aIter] == B[bIter])
		{
			maxSum += (aSum>bSum) ? aSum + A[aIter] : bSum + B[bIter];
			aIter++;
			bIter++;
			aSum = 0;
			bSum = 0;
		}
		else if (A[aIter] < B[bIter])
		{
			aSum += A[aIter++];
		}
		else if (A[aIter] > B[bIter])
		{
			bSum += B[bIter++];
		}
	}

	if (aIter == l1)
	{
		while (bIter != l2)
		{
			bSum += B[bIter++];
		}
	}

	if (bIter == l2)
	{
		while (aIter != l1 )
		{
			aSum += A[aIter++];
		}
	}

	maxSum = aSum > bSum ? maxSum + aSum : maxSum + bSum;
	return maxSum;
}
