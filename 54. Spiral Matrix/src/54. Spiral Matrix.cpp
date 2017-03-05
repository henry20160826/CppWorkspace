//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//
//You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		vector<int> v;
		if (m == 0)
		{
			return v;
		}
		int n = matrix[0].size();
		int rowEnd = m, colEnd = n;
		int rowStart = 0, colStart = 0;
		int i = 0, j = 0;
		while (rowStart < rowEnd && colStart < colEnd)
		{
			for (i = rowStart, j = colStart; j < colEnd; ++j)
			{
				v.push_back(matrix[i][j]);
			}
			for (i = rowStart + 1, j = colEnd - 1; i < rowEnd; ++i)
			{
				v.push_back(matrix[i][j]);
			}
			for (i = rowEnd - 1, j = colEnd - 2; i != rowStart && j >= colStart;
					--j)
			{
				v.push_back(matrix[i][j]);
			}
			for (i = rowEnd - 2, j = colStart; j != colEnd - 1 && i > rowStart;
					--i)
			{
				v.push_back(matrix[i][j]);
			}
			++rowStart;
			++colStart;
			--rowEnd;
			--colEnd;
		}
		return v;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
