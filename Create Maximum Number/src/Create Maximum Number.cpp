//============================================================================
// Name        : Create.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 *
 *  Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

 Example 1:

 nums1 = [3, 4, 6, 5]
 nums2 = [9, 1, 2, 5, 8, 3]
 k = 5
 return [9, 8, 6, 5, 3]

 Example 2:

 nums1 = [6, 7]
 nums2 = [6, 0, 4]
 k = 5
 return [6, 7, 6, 0, 4]

 Example 3:

 nums1 = [3, 9]
 nums2 = [8, 9]
 k = 3
 return [9, 8, 9]

 Credits:
 Special thanks to @dietpepsi for adding this problem and creating all test cases.

 Subscribe to see which companies asked this question
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<int> maxNumber(const vector<int>& nums1, int begin1,
			const vector<int>& nums2, int begin2, int k)
	{
		//length of nums1,nums2 is m,n
		//在保证之后能取到足够数量的数字情况下选择最大的数字
		//两个数组有相同最大值时需要选取之前值较小的一个，为使下次能选到较大的值
		int m = nums1.size();
		int n = nums2.size();
		int maxidInNums1, maxidInNums2;
		vector<int> rvec;
		vector<int> vec1, vec2;
		while (k > 0)
		{
			maxidInNums1 = findSuitableMaxId(nums1, begin1, n - begin2, k);
			maxidInNums2 = findSuitableMaxId(nums2, begin2, m - begin1, k);
			//直接的大于小于好处理，等于的情况需要递归
			if (maxidInNums2 < 0
					|| ((maxidInNums1 >= 0)
							&& nums1[maxidInNums1] > nums2[maxidInNums2]))
			{
				begin1 = maxidInNums1 + 1;
				rvec.push_back(nums1[maxidInNums1]);
				if (m - begin1 >= k && begin2 < n)
				{
					begin2 = maxidInNums2;
				}
			}
			else if (maxidInNums1 < 0
					|| nums1[maxidInNums1] < nums2[maxidInNums2])
			{
				begin2 = maxidInNums2 + 1;
				rvec.push_back(nums2[maxidInNums2]);
				if (n - begin2 >= k && begin1 < n)
				{
					begin1 = maxidInNums1;
				}
			}
			else
			{
				rvec.push_back(nums2[maxidInNums2]);
				--k;

				if (m - maxidInNums1 >= k)
				{
					begin2 = maxidInNums2;

				}
				if (n - maxidInNums2 >= k)
				{
					begin1 = maxidInNums1;
				}
				vec1 = maxNumber(nums1, maxidInNums1 + 1, nums2, begin2, k);
				vec2 = maxNumber(nums1, begin1, nums2, maxidInNums2 + 1, k);
				const vector<int> &bigger = getBiggerOne(vec1, vec2);
				rvec.insert(rvec.end(), bigger.begin(), bigger.end());
				break;
			}

			--k;
		}
		return rvec;
	}
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2,
			int k)
	{
		return maxNumber(nums1, 0, nums2, 0, k);
	}
	const vector<int>& getBiggerOne(const vector<int>& nums1,
			const vector<int>& nums2)
	{
		int len = nums1.size();
		for (int i = 0; i < len; ++i)
		{
			if (nums1[i] > nums2[i])
			{
				return nums1;
			}
			else if (nums1[i] < nums2[i])
			{
				return nums2;
			}
		}
		return nums1;
	}
	int findSuitableMaxId(const vector<int>& nums, int begin, int anotherLen,
			int k)
	{
		int len = nums.size();
		if (begin >= len || begin < 0)
		{
			//取不出任何值，返回下标-1
			return -1;
		}
		int maxid = begin;

		for (int i = begin + 1; i < len; ++i)
		{
			if (nums[maxid] == 9)
			{
				return maxid;
			}
			if (nums[maxid] < nums[i] && (len - i + anotherLen) >= k)
			{
				maxid = i;
			}
		}
		return maxid;
	}
	void print(const vector<int> &nums)
	{
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	void pretreat()
	{

	}
};
//82 / 102 test cases passed.
//	Status: Time Limit Exceeded
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	Solution s;
	int nums1[] =
	{ 6, 9, 2, 3, 6, 7, 9, 9, 0, 9, 6, 2, 3, 3, 3, 4, 7, 4, 5, 6, 8, 5, 0, 4, 9,
			9, 0, 7, 8, 5, 0, 0, 3, 7, 9, 3 };
//	int nums1[] =
//	{ };
	int nums2[] =
	{ 1, 6, 5, 7, 6, 0, 6, 5, 1, 0, 1, 0, 8, 2, 7, 4, 5, 4, 2, 6, 2, 4, 0, 1, 3,
			9, 6, 0, 1, 3, 0, 1, 5, 3, 5, 1, 7, 2, 8, 3, 1, 9, 0, 3, 4, 5, 1, 7,
			6, 1, 5, 9, 8, 5, 9, 9, 8, 7, 6, 0, 3, 9, 0, 2, 8, 7, 5, 4, 0, 5, 1,
			8, 3, 2, 2, 7, 8, 9, 8, 5, 7, 4, 8, 1, 1, 1, 6, 5, 7, 1, 1, 4, 0, 4,
			2, 3, 3, 3, 6, 2, 0, 2, 1, 3, 7, 9, 7, 2, 8, 0, 6, 9, 0, 2, 1, 8, 4,
			6, 7, 9, 2, 5, 9, 4, 6, 1, 9, 5, 7, 9, 4, 1, 0, 6, 8, 0, 1, 3, 9, 4,
			2, 9, 8, 0, 6, 9, 0, 7, 3, 4, 6, 2, 4, 8, 3, 2, 4, 1, 8, 3, 8, 1, 3,
			9, 0, 9, 3, 5, 8, 2, 7, 5, 3, 7, 3, 1, 3, 5, 9, 8 };
	int length;
	length = sizeof(nums1) / sizeof(nums1[0]);
	vector<int> v1(&nums1[0], &nums1[length]);
	cout << length << endl;
	length = sizeof(nums2) / sizeof(nums2[0]);
	vector<int> v2(&nums2[0], &nums2[length]);
	cout << length << endl;
	int k = 180;

	vector<int> vec = s.maxNumber(v1, v2, k);
	s.print(vec);

	return 0;
}
