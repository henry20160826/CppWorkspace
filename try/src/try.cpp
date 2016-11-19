//============================================================================
// Name        : try.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//基本阶乘内容，本程序中没有用到
int mulOfNtoM(int n, int m)
{
	int mul = 1;
	for (int i = n; i <= m; i++)
	{
		mul *= i;
		if (mul < 0)
		{
			cout << "mul溢出" << endl;
			return i;
		}
	}

	return mul;
}
int factorial(int n)
{
	return mulOfNtoM(1, n);
}
int main()
{
//	cout << "Hello World"; // prints Hello World
	int N;
//	cout<<"\b\b"<<"a";
//	while (cin >> N)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			string str;
//			cin >> str;
//			cout << str << endl;
//		}
//	}
	cout<<factorial(25);
	return 0;
}
