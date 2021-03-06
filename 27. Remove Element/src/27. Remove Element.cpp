//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array and a value, remove all instances of that value in place and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3,2,2,3], val = 3
//
//Your function should return length = 2, with the first two elements of nums being 2.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int len = nums.size();
		for (int i = 0; i < len;)
		{
			if (nums[i] == val)
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
