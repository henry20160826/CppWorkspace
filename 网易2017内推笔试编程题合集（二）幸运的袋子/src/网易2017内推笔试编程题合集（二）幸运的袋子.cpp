//============================================================================
// Name        : ����2017���Ʊ��Ա����ϼ����������˵Ĵ���.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
//���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
//��������:
//
//��һ������һ��������n(n �� 1000)
//�ڶ���Ϊn����������xi(xi �� 1000)
//
//
//
//�������:
//
//������Բ��������˵Ĵ�����
//
//
//��������:
//
//3
//1 1 1
//
//
//�������:
//
//2
#include <iostream>
#include <algorithm>
using namespace std;
class Bag
{
public:
	Bag(int *pw, int lenw)
	{
		p = pw;
		len = lenw;
		lenNow = len;
		sort(p, p + len);
		isLucky = checkLucky();
		if (isLucky)
		{
			numLucky++;
		}
	}
private:
	int *p;
	int len;
	int lenNow;
	int sum = 0;
	int product = 1;
	bool isLucky;
	int numLucky = 0;
	bool checkNext()
	{
		sum -= p[lenNow - 1];
		product /= p[lenNow - 1];
		lenNow--;
		return sum > product;
	}
	bool checkLucky()
	{
		for (int i = 0; i < len; i++)
		{
			if (0 != p[i])
			{
				sum += p[i];
				product *= p[i];
			}
		}
		return sum > product;
	}
};

int main()
{
//	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
