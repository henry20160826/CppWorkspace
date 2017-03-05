//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 ¡ú 1,3,2
//3,2,1 ¡ú 1,2,3
//1,1,5 ¡ú 1,5,1

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int len = nums.size();
		int i, j;
		bool isFind = false;
		for (i = len - 2; i >= 0; --i)
		{
			for (j = len - 1; j > i; --j)
			{
				if (nums[i] < nums[j])
				{
					isFind = true;
					break;
				}
			}
			if (isFind)
			{
				break;
			}
		}
//		cout << i << "," << j << endl;
		if (isFind)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			sort(nums.begin() + i + 1, nums.end());
		}
		else
		{
			sort(nums.begin(), nums.end());
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
