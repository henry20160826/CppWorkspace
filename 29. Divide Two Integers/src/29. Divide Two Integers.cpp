//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.
class Solution
{
public:
#define MAX_INT 2147483647
	int divide(int dividend, int divisor)
	{
		//用减法写一个自定义除法
		if (divisor == 0)
		{
			return MAX_INT;
		}
		else if (divisor == 1)
		{
			return dividend;
		}
		else if (divisor == -1)
		{
			if (-dividend == dividend)
			{
				return MAX_INT;
			}
			return -dividend;
		}
		int symbol = -1;
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
		{
			symbol = 1;
		}
		//负值表示的范围更大
		if (dividend > 0)
		{
			dividend = -dividend;
		}
		if (divisor > 0)
		{
			divisor = -divisor;
		}
		int rint = 0;
		while (dividend <= divisor)
		{
			dividend -= divisor;
			++rint;
		}
		if (symbol == -1)
		{
			rint = -rint;
		}
		return rint;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
