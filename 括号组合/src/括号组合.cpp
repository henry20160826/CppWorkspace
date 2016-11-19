//============================================================================
// Name        : 括号组合.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int print(int n, int left, int right)
{
	int leftNum = 0;
	int rightNum = 0;
	if (left == n)
	{
		//左括号已经用完，后面只能全部是右括号
		return 1;
	}
	if (left - right > 0)
	{
		//可以加左括号或右括号
		leftNum = print(n, left + 1, right);
		rightNum = print(n, left, right + 1);
		return leftNum + rightNum;
	}
	else if (left == right)
	{
		//只能加右括号
		leftNum = print(n, left + 1, right);
		return leftNum;
	}
	return 0;
}

int main()
{
	cout << print(4, 0, 0);
	return 0;
}
