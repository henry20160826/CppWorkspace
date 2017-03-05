//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <iostream>
using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		int len = s.length();
		if (1 == numRows || len <= numRows)
		{
			return s;
		}
		int group = numRows * 2 - 2;
		int half = group / 2;
		string rs("");
		int index = 0;
		int remainder = 0;
		int i;
		while (remainder <= half)
		{
			for (i = 0;; ++i)
			{
				index = i * group + remainder;
				if (index < len)
				{
					rs += s[index];
				}
				else
				{
					break;
				}
				if (remainder < half && remainder != 0)
				{
					index = index + group - 2 * remainder;
					if (index < len)
					{
						rs += s[index];
					}
					else
					{
						break;
					}
				}

			}
			++remainder;
		}
		return rs;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
