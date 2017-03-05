//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		//用1表示此位置为空，可以落子
		string s = "";
		int i;
		for (i = 0; i < n; ++i)
		{
			s += '1';
		}
		vector<string> v;
		for (i = 0; i < n; ++i)
		{
			v.push_back(s);
		}
		vector<vector<string>> rvv;
		isPutin(rvv, v, n, 0, n);
		return rvv;
	}
	bool isPutin(vector<vector<string>> &rvv, vector<string> v, int n, int row,
			int residue)
	{
		if (residue == 0)
		{
			rvv.push_back(v);
			return true;
		}
		int j;
		for (j = 0; j < n; ++j)
		{
			if (v[row][j] == '1')
			{
				//分成放在这个位置和不放这个位置两个分支
				v[row][j] = '.';
				isPutin(rvv, v, n, row, residue);
				//Todo 填充禁位
				if (putQueen(v, n, row, j))
				{
					v[row][j] = 'Q';
					isPutin(rvv, v, n, row + 1, residue - 1);
				}
				return false;
			}
		}
		return false;
	}
	bool putQueen(vector<string> &v, int n, int row, int col)
	{
		int i, j;
		//行设为禁位
		for (j = 0; j < n; ++j)
		{
			if (v[row][j] != 'Q')
			{
				v[row][j] = '.';
			}
			else
			{
				return false;
			}
		}
		//列设为禁位
		for (i = 0; i < n; ++i)
		{
			if (v[i][col] != 'Q')
			{
				v[i][col] = '.';
			}
			else
			{
				return false;
			}
		}
		//主对角线设为禁位
		for (i = 0; i < n; ++i)
		{
			if (row - i < 0 || col - i < 0)
			{
				break;
			}
			if (v[row - i][col - i] != 'Q')
			{
				v[row - i][col - i] = '.';
			}
			else
			{
				return false;
			}
		}
		for (i = 0; i < n; ++i)
		{
			if (row + i >= n || col + i >= 0)
			{
				break;
			}
			if (v[row + i][col + i] != 'Q')
			{
				v[row + i][col + i] = '.';
			}
			else
			{
				return false;
			}
		}
		//次对角线设为禁位
		for (i = 0; i < n; ++i)
		{
			if (row - i < 0 || col + i >= n)
			{
				break;
			}
			if (v[row - i][col + i] != 'Q')
			{
				v[row - i][col + i] = '.';
			}
			else
			{
				return false;
			}

		}
		for (i = 0; i < n; ++i)
		{
			if (row + i >= n || col - i < 0)
			{
				break;
			}
			if (v[row + i][col - i] != 'Q')
			{
				v[row + i][col - i] = '.';
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
