//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int i, j, k, medSum, sum;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int rint = nums[0] + nums[1] + nums[2];
		int distance = target - rint;
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
				medSum = nums[i] + nums[j];
				for (k = j + 1; k < len; ++k)
				{
					if (k != j + 1 && nums[k] == nums[k - 1])
					{
						continue;
					}
					sum = medSum + nums[k];
					if (sum <= target && target - sum <= distance)
					{
						rint = sum;
						distance = target - sum;
					}
					else if (sum > target && sum - target < distance)
					{
						rint = sum;
						distance = sum - target;
					}
					else if (sum > target && sum - target >= distance)
					{
						break;
					}
				}
			}
		}
		return rint;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
