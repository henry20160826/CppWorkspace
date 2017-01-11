//============================================================================
// Name        : Two.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> rvec;
		int len = numbers.size();
		int mid;
		int left, right;
		int preTarget;
		bool ifFind = false;
		for (int i = 0; i < len; i++)
		{
			left = i + 1;
			right = len - 1;
			preTarget = target - numbers[i];
			while (right - left >= 0)
			{
				mid = (left + right) / 2;
				if (numbers[mid] < preTarget)
				{
					left = mid + 1;
				}
				else if (numbers[mid] > preTarget)
				{
					right = mid - 1;
				}
				else
				{
					ifFind = true;
					rvec.push_back(i + 1);
					rvec.push_back(mid + 1);
					break;
				}
			}
			if (ifFind)
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