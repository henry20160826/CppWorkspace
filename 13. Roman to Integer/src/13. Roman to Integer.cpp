//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

class Solution
{
public:
	//s小于3999，罗马数字能表示的最大数字3999
	int romanToInt(string s)
	{
		int len = s.size();
		int rint = 0;
		int symbol = 1;
		string biao = "IVXLCDM";
		int last = 0;
//		cout << len << endl;
		for (int i = len - 1; i >= 0; --i)
		{
			if ('I' == s[i])
			{
				if (last <= 1)
				{
					++rint;
				}
				else
				{
					--rint;
				}
				last = 1;
			}
			else if ('V' == s[i])
			{
				if (last <= 5)
				{
					rint += 5;
				}
				else
				{
					rint -= 5;
				}
				last = 5;
			}
			else if ('X' == s[i])
			{
				if (last <= 10)
				{
					rint += 10;
				}
				else
				{
					rint -= 10;
				}
				last = 10;
			}
			else if ('L' == s[i])
			{
				if (last <= 50)
				{
					rint += 50;
				}
				else
				{
					rint -= 50;
				}
				last = 50;
			}
			else if ('C' == s[i])
			{
				if (last <= 100)
				{
					rint += 100;
				}
				else
				{
					rint -= 100;
				}
				last = 100;
			}
			else if ('D' == s[i])
			{
				if (last <= 500)
				{
					rint += 500;
				}
				else
				{
					rint -= 500;
				}
				last = 500;
			}
			else if ('M' == s[i])
			{
				if (last <= 1000)
				{
					rint += 1000;
				}
				else
				{
					rint -= 1000;
				}
				last = 1000;
			}
			else
			{
				return 0;
			}
//			cout << rint << endl;
		}
		return rint;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	string s = "DCXXI";
	Solution so;
	cout << so.romanToInt(s) << endl;
	return 0;
}
