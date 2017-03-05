//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//
//
//Above is a 3 x 7 grid. How many possible unique paths are there?
//
//Note: m and n will be at most 100.

#include <iostream>
using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		return go(m, n);
	}
	int go(int m, int n)
	{
		if (m == 1 || n == 1)
		{
			return 1;
		}
		int a = 0;
		a = go(m - 1, n);
		a += go(m, n - 1);
		return a;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
