//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]

//顺便解决了47题
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//]


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> rvv;
		bool isBegin = false;
		rvv.push_back(nums);
		while (1)
		{
			nextPermutation(nums);
			if (nums != rvv[0])
			{
				rvv.push_back(nums);
			}
			else
			{
				break;
			}
		}
		return rvv;
	}
	void nextPermutation(vector<int>& nums)
	{
		int len = nums.size();
		int i, j;
		bool isFind = false;
		for (i = len - 2; i >= 0; --i)
		{
			for (j = len - 1; j > i; --j)
			{
				if (nums[i] < nums[j])
				{
					isFind = true;
					break;
				}
			}
			if (isFind)
			{
				break;
			}
		}
		//		cout << i << "," << j << endl;
		if (isFind)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			sort(nums.begin() + i + 1, nums.end());
		}
		else
		{
			sort(nums.begin(), nums.end());
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
