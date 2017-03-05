//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//
//Example 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		double rd;
		int m = nums1.size();
		int n = nums2.size();
		int leftNums1, rightNums1, midNums1;
		int leftNums2, rightNums2, midNums2;
		leftNums1 = 0;
		rightNums1 = m - 1;
		leftNums2 = 0;
		rightNums2 = n - 1;
		bool isOne = true; //表示中位数一个数的值还是两个数的平均
		if (0 == (m + n) % 2)
		{
			isOne = false;
		}
		while (leftNums1 <= rightNums1 && leftNums2 <= rightNums2)
		{
			midNums1 = (leftNums1 + rightNums1) / 2;
			midNums2 = (leftNums2 + rightNums2) / 2;
			if (nums1[midNums1] < nums2[midNums2])
			{
				leftNums1 = midNums1 + 1;
				rightNums2 = midNums2 - 1;
			}
			else if (nums1[midNums1] < nums2[midNums2])
			{
				leftNums2 = midNums2 + 1;
				rightNums1 = midNums1 - 1;
			}
			else
			{
				break;
			}
		}
		rd = (nums1[midNums1] + nums2[midNums2]) / 2;
		return rd;
	}
	double findMedianSortedArray(vector<int>& nums1, int begin, int end)
	{
		int len = end - begin + 1;
		int mid = (begin + end) / 2;
		double rd;
		if (1 == len % 2)
		{
			//取一个数做为中位数
			rd = nums1[mid];
		}
		else
		{
			//取两个数的平均值做中位数
			rd = (nums1[mid] + nums1[mid + 1]) / 2;
		}
		return rd;
	}
};
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
