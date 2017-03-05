//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		makeEasy(nums);
//		print(nums);
		int sum = 0;
		int len = nums.size();
		int i;
		return 0;
	}
	void makeEasy(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 2)
		{
			return;
		}
		int sum = nums[0];
		int position = 0;
		int i;
		for (i = 1; i < len;)
		{
			if ((sum >= 0 && nums[i] >= 0) || (sum < 0 && nums[i] < 0))
			{
				sum += nums[i];
				nums.erase(nums.begin() + i);
				--len;
			}
			else
			{
				nums[position] = sum;
				sum = nums[i];
				position = i;
				++i;
			}
		}
		nums[position] = sum;
	}
	void print(vector<int> nums)
	{
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World

	return 0;
}
