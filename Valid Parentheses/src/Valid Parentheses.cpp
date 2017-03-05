//============================================================================
// Name        : Valid.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
//Subscribe to see which companies asked this question

#include <iostream>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		string myString = s;
		int lenOfMyString = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if ('(' == s[i] || '[' == s[i] || '{' == s[i])
			{
				myString[lenOfMyString] = s[i];
				++lenOfMyString;
			}
			else if (')' == s[i] || ']' == s[i] || '}' == s[i])
			{
				if ((lenOfMyString > 0)
						&& ((myString[lenOfMyString - 1] == '(' && s[i] == ')')
								|| (myString[lenOfMyString - 1] == '['
										&& s[i] == ']')
								|| (myString[lenOfMyString - 1] == '{'
										&& s[i] == '}')))
				{

					--lenOfMyString;

				}
				else
				{
					return false;
				}
			}
		}
		if (lenOfMyString == 0)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
