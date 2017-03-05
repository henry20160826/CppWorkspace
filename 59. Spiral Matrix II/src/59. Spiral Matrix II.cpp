//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//You should return the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<int> v;
		vector<vector<int>> rvv;
		int i, j;
		for (i = 0; i < n; ++i)
		{
			v.push_back(0);
		}
		for (i = 0; i < n; ++i)
		{
			rvv.push_back(v);
		}
		int num = 1;
		int start = 0;
		int end = n;
		i = 0;
		j = 0;
		while (start < end)
		{
			for (i = start, j = start; j < end; ++j) //从左向右
			{
				rvv[i][j] = num;
				++num;
			}
			for (i = start + 1, j = end - 1; i < end; ++i) //从上到下
			{
				rvv[i][j] = num;
				++num;
			}
			for (i = end - 1, j = end - 2; i != start && j >= start; --j) //从右向左
			{
				rvv[i][j] = num;
				++num;
			}
			for (i = end - 2, j = start; i > start && j != end - 1; --i) //从下到上
			{
				rvv[i][j] = num;
				++num;
			}
			++start;
			--end;
		}
		return rvv;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
