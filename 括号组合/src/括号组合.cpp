//============================================================================
// Name        : �������.cpp
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
		//�������Ѿ����꣬����ֻ��ȫ����������
		return 1;
	}
	if (left - right > 0)
	{
		//���Լ������Ż�������
		leftNum = print(n, left + 1, right);
		rightNum = print(n, left, right + 1);
		return leftNum + rightNum;
	}
	else if (left == right)
	{
		//ֻ�ܼ�������
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
