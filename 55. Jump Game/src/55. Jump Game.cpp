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
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int len = nums.size();
		int i, j;
		bool isOK = false;
		for (i = 0; i < len - 1; ++i)
		{
			if (nums[i] == 0)
			{
				//判断能不能越过0
				for (j = i - 1; j >= 0; --j)
				{
					if (nums[j] + j > i)
					{
						isOK = true;
						break;
					}
				}
				if (isOK == false)
				{
					return false;
				}
				else
				{
					isOK = false;
				}
			}
		}
		return true;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
