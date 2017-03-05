//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

#include <iostream>
using namespace std;

class Solution
{
public:
	//����intΪ32λʱ�����
	int myAtoi(string str)
	{
		//����������������������⣬���ǳ��ַǷ��ַ�
		int len = str.length();
		if (len == 0)
		{
			return 0;
		}
		int rint = 0;
		int symbol = 1;
		int start = 0;
		//����ǰ��Ŀո�
		while (start < len && str[start] == ' ')
		{
			++start;
		}
		//�����һλ���ܴ��ڵķ���
		if (str[start] == '-')
		{
			symbol = -1;
			++start;
		}
		else if (str[start] == '+')
		{
			++start;
		}
//		cout << "len:" << len << endl;
//		cout << "start:" << start << endl;
//		cout << "symbol:" << symbol << endl;
		//������֮ǰ���������Ƿ�����
		//���崦������
		for (int i = start; i < len; ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (rint > 214748364 || rint == 214748364 && str[i] >= '7')
				{
//					cout << "�����" << endl;
					//32λint�ܱ�ʾ���������
					return 2147483647;
				}
				else if (rint < -214748364
						|| rint == -214748364 && str[i] >= '8')
				{

//					cout << "�����" << endl;
					//32Ϊint�ܱ�ʾ����С����
					return -2147483648;
				}
				else //�����
				{
					rint = rint * 10 + (str[i] - '0') * symbol;
				}

			}
			else
			{
				break;
			}
		}
//		cout << symbol << endl;
		return rint;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	string str = "2147483648";
	Solution s;
	cout << s.myAtoi(str) << endl;
	return 0;
}
