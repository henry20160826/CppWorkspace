//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//Note:
//Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> rvec;
		int len = digits.length();
		for (int i = 0; i < len; i++)
		{
			rvec = letterCombinations(rvec, digits[i]);
		}
		return rvec;
	}
	vector<string> letterCombinations(vector<string> &vstr, char digit)
	{
		if (digit == '1')
		{
			return vstr;
		}
		vector<string> rvector;
		int m;
		int start = 0;
		if (digit > '1' && digit < '7')
		{
			//搞出3份
//			cout << "3份" << endl;
			m = 3;
		}
		else if (digit == '7')
		{
			//搞出4份
//			cout << "4份" << endl;
			m = 4;
		}
		else if (digit == '8')
		{
			m = 3;
			start = 1;
		}
		else if (digit == '9')
		{
			m = 4;
			start = 1;
		}
		else
		{
			return vstr;
		}
		int len = vstr.size();
		char c[1];
		if (len == 0)
		{
			for (int i = 0; i < m; ++i)
			{
				c[0] = 'a' + (digit - '2') * 3 + i + start;
				rvector.push_back(c);
			}
		}
		else
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < len; ++j)
				{
					c[0] = 'a' + (digit - '2') * 3 + i + start;
					rvector.push_back(vstr[j] + c);
				}
			}
		}
//		print(rvector);
		return rvector;
	}
	void print(vector<string> s)
	{
		int len = s.size();
		cout << "begin" << endl;
		for (int i = 0; i < len; ++i)
		{
			cout << s[i] << endl;
		}
		cout << "end" << endl;
	}
};
//(digit - '1') * 3 + i +
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
