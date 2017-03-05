//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int len = nums.size();
		for (int i = 1; i < len;)
		{
			if (nums[i - 1] == nums[i])
			{
				nums.erase(nums.begin() + i);
				--len;
			}
			else
			{
				++i;
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
