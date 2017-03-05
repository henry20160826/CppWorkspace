//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int trap(vector<int>& height)
	{
		int len = height.size();
		int water = 0;
		int begin = 0;
		int end = 0;
		int i;
		while (begin < len)
		{
			end = getGround(height, len, begin);
			if (end != -1)
			{
				water += getWater(height, begin, end);
				begin = end;
			}
			else
			{
				++begin;
			}
		}
		return water;
	}
	int getGround(vector<int>& height, int len, int begin)
	{
		if (height[begin] == 0)
		{
			return -1;
		}
		int mid = begin + 1;
		if (mid >= len || height[begin] <= height[mid])
		{
			return -1;
		}
		int i;
		for (i = mid + 1; i < len; ++i)
		{
			if (height[i] > height[begin])
			{
				return i;
			}
			if (height[i] > height[mid])
			{
				mid = i;
			}
		}
		return mid;
	}
	int getWater(vector<int>& height, int begin, int end)
	{
		int lenOfGround = end - begin - 1;
		if (lenOfGround < 1)
		{
			return 0;
		}
		int water = height[begin] < height[end] ? height[begin] : height[end];
		water *= lenOfGround;
		for (int i = begin + 1; i < end; ++i)
		{
			water -= height[i];
		}
//		cout << begin << endl;
//		cout << end << endl;
//		cout << water << endl;
		return water;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
