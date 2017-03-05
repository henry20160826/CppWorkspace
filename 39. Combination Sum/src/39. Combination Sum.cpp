//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.
//
//For example, given candidate set [2, 3, 6, 7] and target 7,
//A solution set is:
//
//[
//  [7],
//  [2, 2, 3]
//]

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		int len = candidates.size();
		int remainder = 0;
		for (int i = 0; i < len; ++i)
		{
			remainder = target % candidates[i];
			for()
			{

			}
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
