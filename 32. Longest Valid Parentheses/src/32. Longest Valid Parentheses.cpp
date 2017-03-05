//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int lenOfString = s.length();
		vector<int> v; //记录未被匹配左括号的数量
		int unMatched = 0; //记录当前还未匹配的左括号数量
		int i, max = 0, lenOfVector;
		v.push_back(-1);
		for (i = 0; i < lenOfString; ++i)
		{
			if (s[i] == '(')
			{
				v.push_back(i);
				++unMatched;
			}
			else if (unMatched > 0 && s[i] == ')')
			{
				--unMatched;
				v.pop_back();
			}
			else
			{
				//遇到不能匹配的')'，找到前面最大的匹配括号串，后面重新开始分析
				v.push_back(i);
				max = getMax(v, max);
				unMatched = 0;
				v.clear();
				v.push_back(i);
			}
		}
		v.push_back(lenOfString);
		max = getMax(v, max);
		return max;
	}
	int getMax(vector<int> v, int max)
	{
		int lenOfVector = v.size();
		for (int i = 0; i < lenOfVector - 1; ++i)
		{
			if (v[i + 1] - v[i] - 1 > max)
			{
				max = v[i + 1] - v[i] - 1;
			}
		}
		return max;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
