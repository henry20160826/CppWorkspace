//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//
//Example:
//
//Input: "cbbd"
//
//Output: "bb"

#include <iostream>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		int end;
		for (int start = 0; start < len; ++start)
		{
			for (int j = 0;; ++j)
			{

			}
		}
		return 0;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
