//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//几个求和的题目这是第一个不能暴力算的。也想到之前可以用更好的方法
class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int i, j, k, l, sum2, sum3;
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
				sum2 = nums[i] + nums[j];
				for (k = j + 1; k < len; ++k)
				{
					if (k != j + 1 && nums[k] == nums[k - 1])
					{
						continue;
					}
					sum3 = sum2 + nums[k];

					for (l = k + 1; l < len; ++l)
					{
						if (l != k + 1 && nums[l] == nums[l - 1])
						{
							continue;
						}
						else if (sum3 + nums[l] == target)
						{
							vector<int> v;
							v.push_back(nums[i]);
							v.push_back(nums[j]);
							v.push_back(nums[k]);
							v.push_back(nums[l]);
							rvv.push_back(v);
						}
						else if (sum3 + nums[l] > target)
						{
							break;
						}
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
