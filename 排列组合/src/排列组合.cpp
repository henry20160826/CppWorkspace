//============================================================================
// Name        : ÅÅÁÐ×éºÏ.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include "Arrangement.h"
#include "Combination.h"
//#include<algorithm>
using namespace std;

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	int N = 5;
	int *p = new int[N];
	for (int i = 2; i < N + 2; i++)
	{
		p[i - 2] = i;
	}
//	Arrangement arrangement(p, N);
//	cout << arrangement.printAllArrangement();

	Combination combination(p, N, 2);
	cout << combination.printAllCombination();
	return 0;
}
