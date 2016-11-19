//============================================================================
// Name        : ÷‹√˘Ã⁄—∂ª˙ ‘1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void trans(int n)
{
	int left = -90, right = 90;
	int mid;
	while (right - left >= 6)
	{
		mid = (right + left) / 2;
		if (n < mid)
		{
			cout << 0;
			right = mid;
		}
		else
		{
			cout << 1;
			left = mid;
		}
	}
}
int main()
{
//	cout << "Hello World" << endl; // prints Hello World
	trans(80);
	return 0;
}
