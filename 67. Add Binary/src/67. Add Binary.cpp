//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include <iostream>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int alen = a.length();
		int blen = b.length();
		int i;
		int maxlen = alen > blen ? alen : blen;
		string rs(++maxlen, 0);
		for (i = 1; alen - i >= 0 && blen - i >= 0; ++i)
		{
			rs[maxlen - i] = a[alen - i] - '0' + b[blen - i] - '0';
		}
		for (; alen - i >= 0; ++i)
		{
			rs[maxlen - i] = a[alen - i] - '0';
		}
		for (; blen - i >= 0; ++i)
		{
			rs[maxlen - i] = b[blen - i] - '0';
		}
		int carry = 0;
		for (i = maxlen - 1; i >= 0; --i)
		{
			rs[i] += carry;
			carry = rs[i] / 2;
			rs[i] %= 2;
			rs[i] += '0';
		}
		if (rs[0] == '0')
		{
			return rs.substr(1, maxlen);
		}
		return rs;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
