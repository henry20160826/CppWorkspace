//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int len = s.length();
		if (len == 0)
		{
			return 0;
		}
		int rlen = 1;
		int tempRlen = 1;
		bool isRepeat = false;
		int j = 0;
		int start = 0;
		for (int i = 1; i < len; ++i)
		{
			j = start;
			for (; j < i; ++j)
			{
				if (s[j] == s[i])
				{
					isRepeat = true;
					break;
				}
			}
			if (isRepeat)
			{
				if (tempRlen > rlen)
				{
					rlen = tempRlen;
				}
//				cout << j << "," << i << "," << tempRlen << endl;
				start = j + 1;
				tempRlen = i - j;
				isRepeat = false;
			}
			else
			{
				++tempRlen;
			}

		}
		if (tempRlen > rlen)
		{
			rlen = tempRlen;
		}
		return rlen;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	string s = "abcabcbb";
	Solution so;
	cout << so.lengthOfLongestSubstring(s) << endl;
	return 0;
}