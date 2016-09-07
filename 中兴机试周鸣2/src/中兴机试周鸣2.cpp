//============================================================================
// Name        : 中兴机试周鸣2.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int* swapDataAndIndex(int *arr, int len)
{
	int *p = new int[len];
	for (int i = 0; i < len; i++)
	{
		p[arr[i]] = i;
	}
	return p;
}

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
