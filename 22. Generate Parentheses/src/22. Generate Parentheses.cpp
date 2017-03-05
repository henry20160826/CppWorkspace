//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]

#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		return generateParenthesis("", n, n);
	}
	vector<string> generateParenthesis(string s, int left, int right)
	{
//		cout << s << endl;
		vector<string> rv;
		if (left > 0)
		{
			vector<string> r = generateParenthesis(s + "(", left - 1, right);
			rv.insert(rv.end(), r.begin(), r.end());
		}
		if (right > 0 && right > left)
		{
			vector<string> r = generateParenthesis(s + ")", left, right - 1);
			rv.insert(rv.end(), r.begin(), r.end());
		}
		if (right == 0)
		{
			rv.push_back(s);
		}
		return rv;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
