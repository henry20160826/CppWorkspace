//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place?

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		int i, j, k;
		int newi, newj;
		int jlen = n / 2;
		int ilen = jlen + n % 2;
		int temp1, temp2;
		for (i = 0; i < ilen; ++i)
		{
			for (j = 0; j < jlen; ++j)
			{
				newi = i;
				newj = j;
				temp1 = matrix[newi][newj];
				for (k = 0; k < 4; k++)
				{
					temp2 = newi;
					newi = newj;
					newj = n - 1 - temp2;
					temp2 = matrix[newi][newj];
					matrix[newi][newj] = temp1;
					temp1 = temp2;
				}
			}
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
