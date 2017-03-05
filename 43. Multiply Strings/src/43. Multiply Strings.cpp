//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
//
//Note:
//
//    The length of both num1 and num2 is < 110.
//    Both num1 and num2 contains only digits 0-9.
//    Both num1 and num2 does not contain any leading zero.
//    You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <memory.h>
using namespace std;

class Solution
{
public:
	//两个正数相乘，不需要考虑正负问题
	string multiply(string num1, string num2)
	{
		int lenNum1 = num1.length();
		int lenNum2 = num2.length();
		//此处使用char型的数组会越界，char 8位，能表示的最大数为127
		int *p = new int[lenNum1 + lenNum2];
		memset(p, 0, (lenNum1 + lenNum2) * sizeof(int)); //将内存初始化为0
//		print(p, lenNum1 + lenNum2);
		int i, j;
		for (i = lenNum1 - 1; i > -1; --i)
		{
			for (j = lenNum2 - 1; j > -1; --j)
			{
				p[j + i + 1] += ((num1[i] - '0') * (num2[j] - '0'));
			}
		}
//		print(p, lenNum1 + lenNum2);
		j = 0; //现在表示进位
		for (i = lenNum1 + lenNum2 - 1; i > -1; --i)
		{
			p[i] += j;
			j = p[i] / 10;
			p[i] %= 10;
		}
		j = lenNum1 + lenNum2;
//		print(p, lenNum1 + lenNum2);
		string rs = "";
		int begin = 0;
		while (p[begin] == 0 && begin < j)
		{
			++begin;
		}
		for (i = begin; i < j - 1; ++i)
		{
			rs += (p[i] + '0');
		}
		rs += (p[j - 1] + '0');
		return rs;
	}
	void print(int *p, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
