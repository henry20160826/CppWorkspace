//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
using namespace std;

class Solution
{
public:
	//暴力方法
	//可以使用更快的字符串匹配算法
	int strStr(string haystack, string needle)
	{
		int len_haystack = haystack.length();
		int len_needle = needle.length();
		int i, j;
		for (i = 0; i < len_haystack; ++i)
		{
			for (j = 0; j < len_needle; ++j)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (j == len_needle)
			{
				return i;
			}
		}
		if (j == len_needle)
		{
			return i;
		}
		return -1;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
