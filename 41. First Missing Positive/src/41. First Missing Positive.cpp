//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int len = nums.size();
		if(len==0)
		{
			return 1;
		}
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] < 0)
			{
				return i;
			}
		}
		return len;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
