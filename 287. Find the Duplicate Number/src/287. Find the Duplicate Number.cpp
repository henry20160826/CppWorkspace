//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
//Note:
//
//    You must not modify the array (assume the array is read only).
//    You must use only constant, O(1) extra space.
//    Your runtime complexity should be less than O(n2).
//    There is only one duplicate number in the array, but it could be repeated more than once.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	//暴力方法，时间复杂度O(n^2)
//	int findDuplicate(vector<int>& nums)
//	{
//		int len = nums.size();
//		int i, j;
//		for (i = 0; i < len; ++i)
//		{
//			for (j = i + 1; j < len; ++j)
//			{
//				if (nums[i] == nums[j])
//				{
//					return nums[i];
//				}
//			}
//		}
//		return -1;
//	}

//O(n)方法
	int findDuplicate(vector<int>& nums)
	{
		int len = nums.size();
		int slow = 0, fast = 0;
		int times = 0;
		while (times <= len)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			++times;
			if (slow == fast)
			{
				fast = 0;
				while (fast != slow)
				{
					fast = nums[fast];
					slow = nums[slow];
				}
				return slow;
			}
		}
		return -1;
	}
};
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
