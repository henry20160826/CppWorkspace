//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//click to show spoilers.
//Have you thought about this?
//
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream>
using namespace std;

void prints(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << endl;
	}
}

class Solution
{
public:
	//处理int为32为时的情况
	int reverse(int x)
	{
		int a[21] =
		{ 0 };
		int i;
		for (i = 0; x != 0; ++i)
		{
			a[i] = x % 10;
			x /= 10;
		}
		int len = i;
		for (i = 0; i < len; ++i)
		{
			if (x > 214748364 || (x == 214748364 && a[i] > 7)) //判断是否正溢出
			{
				return 0;
			}
			else if (x < -214748364 || (x == -214748364 && a[i] < -8)) //判断是否负溢出
			{
				return 0;
			}
			else
			{
				x = x * 10 + a[i];
			}
		}
		return x;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
