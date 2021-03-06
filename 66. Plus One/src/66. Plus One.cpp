//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int len = digits.size();
		int carry = 1;
		int i;
		for (i = len - 1; i >= 0; --i)
		{
			digits[i] += carry;
			carry = digits[i] / 10;
			digits[i] %= 10;
			if (0 == carry)
			{
				break;
			}
		}
		if (1 == carry)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
