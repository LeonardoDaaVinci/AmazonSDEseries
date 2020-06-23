Rotate Array in clockwise direction :
	Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

Solution:
	1. The solution to this problem needs just one routine which InvertArray function.
	2. Once you have it, invert the first D elements.
	3. Following the invert the remaining N-D element seperately.
	4. Final step is to invert the whole N elements once.
	5. This results in the array with its elements rotated D times in clockwise direction.
	
CODE :

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
// Function to invert the given array.
// CASE 1:
// If the length of the array is odd, we need to iterate till (floor of n/2) from start of array,
// to swap with corresponding element in the other end

// CASE 2:
// If the length of the array is even, we need to iterate till (n/2 -1) from start of array to swap
// with corresponding element from the other end.

void InvertArray(int *arr, int n)
{
	int iter = 0;
	if (n % 2 == 0)
		iter = n / 2 - 1;
	else
		iter = floor(n / 2);

	for (int i = 0; i<=iter; i++) // Equal to is important
	{
		int temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}

}

// Function to rotate an array of length n, d times in clockWise Direction.
void rotateArr(int arr[], int d, int n) {

	InvertArray(arr, d); // Invert the first d element
	InvertArray(arr+d, n - d); // Invert last (n-d) elements 
	InvertArray(arr, n); // Invert the whole array now -> Result of which is the array rotated d times 
						 // in clockwise direction.

}

	
