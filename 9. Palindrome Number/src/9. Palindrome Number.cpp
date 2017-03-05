//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>
using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}
		int max = 1;
		while (x / max / 10 != 0)
		{
			max *= 10;
		}
		int min = 1;
		while (max >= min)
		{
			if (x / max % 10 == x / min % 10)
			{
				max /= 10;
				min *= 10;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
