//============================================================================
// Name        : ����.cpp
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
	//ֻʵ���������֣�û��ʵ��С������
public:
	//�±�Ϊ0�������λ
	char *num;
	//Ĭ�ϳ�ʼ���������ֳ�ʼ��Ϊ0
	BigNum()
	{
		//0�ķ���Ϊ��
		lenNow = 1;
		num = new char[len]();
	}
	//ʹ��int��ʼ���������ݳ�ʼ��Ϊa
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
			//��ֵ����ֱ�����ڼ��㣬�����ʱ�����ʽ����
			num[lenNow] = a % 10;
			a /= 10;
//			cout << "a:" << a << endl;
		}
	}
	//ʹ���ַ�����ʼ���������ݳ�ʼ��Ϊs
	BigNum(char *s, int lenNoww, int lenw = 100) :
			lenNow(lenNoww), len(lenw)
	{
		num = new char[len]();
		//���ַ���ֵ��
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
		//��ʽ���Ʋ�д�ں������棬������Χ����
		if (!symbol)
		{
			cout << "-";
		}
		for (int i = lenNow - 1; i >= 0; i--)
		{
			//�����ʽ����
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
		//ʵ��this�ľ���ֵ��a�ľ���ֵ������this�ķ��ţ�symbol��
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
		//����this�ľ���ֵ��a�ľ���ֵ������this�ķ���
		int alen = a.getLength();
		int longlen = lenNow > alen ? lenNow : alen;

		return this;
	}
	BigNum* multiply(int a)
	{
		//������int���������
		BigNum bigA(a);
		return multiply(bigA);
	}
	BigNum* multiply(BigNum a)
	{
		BigNum *result = new BigNum();
		result->symbol = symbol == a.symbol ? true : false;
		//ʵ�ֳ˷�����
		int alen = a.getLength();
		//�ж�������Ƿ�������
		if (alen + lenNow + 1 > len)
		{
			cout << "�˴γ˷��������" << endl;
			return NULL;
		}
		else
		{
			//�����������ʼ����
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
			//�жϳ˷����λ��
			result->lenNow =
					result->num[lenNow + alen] == 0 ?
							lenNow + alen : lenNow + alen - 1;
		}
		return result;
	}

private:
	int lenNow = 0;//��ǰ����Ч����λ��
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
