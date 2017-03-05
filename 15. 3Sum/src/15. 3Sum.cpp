//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	//这是暴力方法
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int i, j, k, medSum, sum;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<vector<int>> rvv;
		for (i = 0; i < len; ++i)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (j = i + 1; j < len; ++j)
			{
				if (j != i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				medSum = nums[i] + nums[j];
				for (k = j + 1; k < len; ++k)
				{
					if (k != j + 1 && nums[k] == nums[k - 1])
					{
						continue;
					}
					else if (medSum + nums[k] == 0)
					{
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						v.push_back(nums[k]);
						rvv.push_back(v);
					}
					else if (medSum + nums[k] > 0)
					{
						break;
					}
				}
			}
		}
		return rvv;
	}


};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
