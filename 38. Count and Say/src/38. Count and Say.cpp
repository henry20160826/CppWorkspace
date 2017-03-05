//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

#include <iostream>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string rs = "";
		int now = 0, count = 0;
		int begin = 1;
		while (n / begin > 10)
		{
			begin *= 10;
		}
		while (begin > 0)
		{
			if (now == n / begin)
			{
				++count;
			}
			else
			{
				if (count > 1)
				{
					rs += count + '0';
				}
				if (count != 0)
				{
					rs += now + '0';
				}
				now = n / begin;
				count = 1;
			}
			n %= begin;
			begin /= 10;
		}
		if (count > 1)
		{
			rs += count + '0';
		}
		if (count != 0)
		{
			rs += now + '0';
		}
		return rs;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
