//============================================================================
// Name        : С������1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//�������������ʵ��,num������ ������к�һ�����ʵ�����ĸ������ǰ��һ���������һ����ĸ��ͬ���򷵻�һ  ���򷵻ظ�һ
#include <iostream>
#include <string.h>
using namespace std;
int judge(int num, char **p)
{
	char now;
	int len = strlen(*p);
	char last = *(*p + len - 1);
	p++;

	for (int i = 1; i < num; i++)
	{
		now = **p;
		cout << "lastlen:" << len << endl;
		cout << "last:" << last << endl;
		cout << *p << endl;
		cout << i << ":" << now << endl;
		if (now != last)
		{
			return -1;
		}
		len = strlen(*p);
		last = *(*p + len - 1);
		p++;
	}
	return 1;
}
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	char a[] = "abc";
	char b[] = "cmab";
	char c[] = "bdafafafac";
	char d[] = "cgwregweg";
	char* z[] =
	{ a, b, c, d };
	cout << judge(4, z);
	return 0;
}
