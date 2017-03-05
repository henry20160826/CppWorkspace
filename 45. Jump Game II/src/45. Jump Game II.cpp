//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int len = nums.size();
		int i = 0, point = len - 1;
		while (point != 0)
		{
			point = getPoint(nums, point);
			++i;
		}
		return i;
	}
	int getPoint(vector<int> &nums, int point)
	{
		int i;
		for (i = 0; i < point; ++i)
		{
			if (nums[i] + i >= point)
			{
				return i;
			}
		}
		return point;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
