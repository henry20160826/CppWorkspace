//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return:
//
//[
//  ["ate", "eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//
//Note: All inputs will be in lower-case.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> rvv;
		int len = strs.size();
		int i, j;
		bool isFind;
		int lenRvv = 0;
		for (i = 0; i < len; ++i)
		{
			isFind = false;
			for (j = 0; j < lenRvv; ++j)
			{
				isFind = isSameGroup(strs[i], rvv[j][0]);
				if (isFind)
				{
					rvv[j].push_back(strs[i]);
					break;
				}
//				cout << isFind << endl;
			}
			if (false == isFind)
			{
				vector<string> v;
				v.push_back(strs[i]);
				rvv.push_back(v);
				++lenRvv;
			}
		}
		return rvv;
	}
	bool isSameGroup(string s1, string s2)
	{
		int len1 = s1.length();
		int len2 = s2.length();
		if (len1 != len2)
		{
			return false;
		}
		int record[26] =
		{ 0 };
		int i;
		for (i = 0; i < len1; ++i)
		{
			++record[s1[i] - 'a'];
		}
		for (i = 0; i < len2; ++i)
		{
			if (--record[s2[i] - 'a'] < 0)
			{
				return false;
			}
		}
		for (i = 0; i < 26; ++i)
		{
			if (record[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
