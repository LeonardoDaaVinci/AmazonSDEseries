Min distance based on position:
	You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y.
	
Solution:
	1. Iterate throught the whole array and get all the positins of x and y in the given array.
	2. Now we have positions of x and y, we need to permute and find the most minimum distance.
	3. This permutation we do through the two for loops. O(m x n)


CODE:
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int minDist(int a[], int n, int x, int y) {
	// code here
	vector<int> xpos;
	vector<int> ypos;
	for (int i = 0; i<n; i++)
	{
		if (a[i] == x)
			xpos.push_back(i);
		else if (a[i] == y)
			ypos.push_back(i);
	}

	int dist = INT_MAX;

	if (xpos.size()==0 || ypos.size()==0)
		return -1;
	else
	{
		for (int i = 0; i < xpos.size(); i++)
		{
			for (int j = 0; j < ypos.size(); j++)
			{
				dist = min(abs(xpos[i] - ypos[j]), dist);
			}
		}
	}

	return dist;
}
