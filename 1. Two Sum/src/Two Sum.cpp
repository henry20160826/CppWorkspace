//============================================================================
// Name        : Two.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> rvec;
		int len = nums.size();
		bool flag = false;
		for (int i = 0; i < len; ++i)
		{
			for (int j = len - 1; j > i; --j)
			{
				if (nums[i] + nums[j] == target)
				{
					flag = true;
					rvec.push_back(i);
					rvec.push_back(j);
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		return rvec;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
