//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution
{
public:
	//计算x的n次方
	double myPow(double x, int n)
	{
		if (0 == n)
		{
			return 1;
		}
		double rd = x;
		bool isPositive = true;
		if (n < 0)
		{
			isPositive = false;
			n = -n;
		}
		for (int i = 1; i < n; ++i)
		{
			rd *= x;
		}
		if (false == isPositive)
		{
			return 1 / rd;
		}
		return rd;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
