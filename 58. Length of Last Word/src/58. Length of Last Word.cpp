//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example,
//Given s = "Hello World",
//return 5.

#include <iostream>
using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int len = s.length();
		if (len == 0)
		{
			return 0;
		}
		int i;
		bool isFind = false;
		for (i = len - 1; i >= 0; --i)
		{
			if (s[i] == ' ' && isFind)
			{
				break;
			}
			else if (s[i] == ' ' && false == isFind)
			{
				--len;
			}
			else if (s[i] != ' ')
			{
				isFind = true;
			}
		}
		if (isFind)
		{
			return len - i - 1;
		}

		return 0;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
