//============================================================================
// Name        : 大数.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

class BigNum
{
	//只实现整数部分，没有实现小数部分
public:
	//下标为0的是最低位
	char *num;
	//默认初始化，将数字初始化为0
	BigNum()
	{
		//0的符号为正
		lenNow = 1;
		num = new char[len]();
	}
	//使用int初始化，将数据初始化为a
	BigNum(int a, int lenw = 100) :
			len(lenw)
	{
		if (a < 0)
		{
			symbol = false;
			a = -a;
		}
		num = new char[len]();
		for (; lenNow < len && a > 0; lenNow++)
		{
			//数值可以直接用于计算，在输出时处理格式问题
			num[lenNow] = a % 10;
			a /= 10;
//			cout << "a:" << a << endl;
		}
	}
	//使用字符串初始化，将数据初始化为s
	BigNum(char *s, int lenNoww, int lenw = 100) :
			lenNow(lenNoww), len(lenw)
	{
		num = new char[len]();
		//将字符数值化
		for (int i = 0; i < lenNow - 1; i++)
		{
			num[i] = s[i] - '0';
		}
		if ('-' == s[lenNow - 1])
		{
			symbol = false;
		}
		else
		{
			num[lenNow - 1] = s[lenNow - 1] - '0';
		}
	}
	void print()
	{
		//格式控制不写在函数里面，留给外围控制
		if (!symbol)
		{
			cout << "-";
		}
		for (int i = lenNow - 1; i >= 0; i--)
		{
			//处理格式问题
			cout << (char) ('0' + num[i]);
		}
//		cout << endl;
	}
	void printAll()
	{
		if (!symbol)
		{
			cout << "-";
		}
		else
		{
			cout << "+";
		}
		for (int i = len - 1; i >= 0; i--)
		{
			cout << (char) ('0' + num[i]);
		}
//		cout << endl;
	}
	int getLength()
	{
		return lenNow;
	}
	BigNum* abosluteAdd(BigNum a)
	{
		//实现this的绝对值加a的绝对值，保留this的符号（symbol）
		int alen = a.getLength();
		int longlen = lenNow > alen ? lenNow : alen;
		lenNow = longlen;
		int carryOut = 0;
		for (int i = 0; i < lenNow; i++)
		{
			num[i] += a.num[i] + carryOut;
			carryOut = num[i] / 10;
			num[i] %= 10;
		}
		if (carryOut > 0)
		{
			num[lenNow] = 1;
			lenNow++;
		}
		return this;
	}
	BigNum* absoluteSub(BigNum a)
	{
		//计算this的绝对值减a的绝对值，保留this的符号
		int alen = a.getLength();
		int longlen = lenNow > alen ? lenNow : alen;

		return this;
	}
	BigNum* multiply(int a)
	{
		//大数与int型数据相乘
		BigNum bigA(a);
		return multiply(bigA);
	}
	BigNum* multiply(BigNum a)
	{
		BigNum *result = new BigNum();
		result->symbol = symbol == a.symbol ? true : false;
		//实现乘法功能
		int alen = a.getLength();
		//判断运算后是否造成溢出
		if (alen + lenNow + 1 > len)
		{
			cout << "此次乘法将会溢出" << endl;
			return NULL;
		}
		else
		{
			//不会溢出，开始计算
			int carryOut1 = 0;
			for (int i = 0; i < alen; i++)
			{
				for (int j = 0; j < lenNow + i + 1; j++)
				{
					result->num[i + j] += a.num[i] * num[j] + carryOut1;
					carryOut1 = result->num[i + j] / 10;
					result->num[i + j] %= 10;
				}
			}
			//判断乘法后的位数
			result->lenNow =
					result->num[lenNow + alen] == 0 ?
							lenNow + alen : lenNow + alen - 1;
		}
		return result;
	}

private:
	int lenNow = 0;//当前是有效数字位数
	int len = 100;
	bool symbol = true;
};

int main()
{
	BigNum a(777);
	char c[] = "999999";
	a.multiply(999999)->printAll();
	return 0;
}
