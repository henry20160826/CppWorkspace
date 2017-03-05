//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int len = nums.size();
		bool isFind = false;
		vector<int> rv;
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == target && isFind == false)
			{
				rv.push_back(i);
				rv.push_back(i);
				isFind = true;
			}
			else if (nums[i] == target && isFind == true)
			{
				++rv[1];
			}
			else if (nums[i] != target && isFind == true)
			{
				break;
			}
		}
		if (isFind == false)
		{
			rv.push_back(-1);
			rv.push_back(-1);
		}
		return rv;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
