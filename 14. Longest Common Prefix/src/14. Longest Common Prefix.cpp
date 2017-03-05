//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Write a function to find the longest common prefix string amongst an array of strings

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		int len = strs.size();
		if (len <= 0)
		{
			return "";
		}
		int i, j;
		int minLen = strs[0].length();
		if (len == 1)
		{
			cout << minLen << endl;
			return strs[0].substr(0, minLen);
		}
		char c;
		for (i = 1; i < len; ++i)
		{
			if (strs[i].length() < minLen)
			{
				minLen = strs[i].length();
			}
		}
		if (minLen <= 0)
		{
			return "";
		}
		for (j = 0; j < minLen; ++j)
		{
			c = strs[0][j];
			for (i = 1; i < len; ++i)
			{
				if (c != strs[i][j])
				{
					return strs[0].substr(0, j);
				}
			}
		}
		return strs[0].substr(0, minLen);
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	vector<string> s;
	Solution so;
	cout << so.longestCommonPrefix(s) << endl;
	return 0;
}
