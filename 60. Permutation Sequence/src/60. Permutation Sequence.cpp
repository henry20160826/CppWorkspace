//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//The set [1,2,3,…,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence (ie, for n = 3):
//
//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"
//
//Given n and k, return the kth permutation sequence.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力方法超时
/*class Solution
 {
 public:
 string getPermutation(int n, int k)
 {
 vector<int> v;
 int i;
 for (i = 1; i <= n; ++i)
 {
 v.push_back(i);
 }
 for (i = 1; i < k; ++i)
 {
 nextPermutation(v);
 }
 string rs = "";
 for (i = 0; i < n; i++)
 {
 rs += '0' + v[i];
 }
 return rs;
 }
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
 };*/

//smarter way
class Solution
{
public:
	string getPermutation(int n, int k)
	{
		int i, n1;
		n1 = 1;
		for (i = 1; i <= n; ++i)
		{
			n1 *= i;
			if (n1 >= k)
			{
				break;
			}
		}
	}
	string getPermutation(int k)
	{
		int i;
		int n = 1;
		//计算几个数的排列首次超过k，结果为n+1
		for (i = 1;; ++i)
		{
			if (n * i >= k)
			{
				break;
			}
			n *= i;
		}
		//需要n+1个数表示第k个排列

		int a;
		string rs = "";
		while ()
		{
			a = k / n;
			rs += '0' + a;
			k %= n;
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
