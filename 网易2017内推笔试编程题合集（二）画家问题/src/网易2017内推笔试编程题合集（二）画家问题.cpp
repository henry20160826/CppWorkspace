//============================================================================
// Name        : ����2017���Ʊ��Ա����ϼ���������������.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//�����һ�����ң������������һ����������������û���㹻��ɫ�����ϡ�Ϊ��������򵥣���������������ʾ��ͬ��ɫ�����ϡ���֪���������Ҫ��n����ɫ�����ϣ������ڿ���ȥ�̵깺��һЩ���ϣ������̵겻�ܱ�֤�ܹ�Ӧ������ɫ�����ϣ���������Ҫ�Լ����һЩ���ϡ�������ֲ�һ������ɫA����ɫB���Ͽ��Բ���(A XOR B)������ɫ������(�²���������Ҳ��������������ϲ����µ���ɫ,XOR��ʾ������)�������ڼ��Լ�ľ������빺����ٵ����Ͼ�����Ҫ�����Լ�ְ����Ա������Ҫ����������������Ҫ��������ɫ�����ϣ�
//��������:
//
//��һ��Ϊ�����������Ҫ����ɫ����n (1 �� n �� 50)
//�ڶ���Ϊn����xi(1 �� xi �� 1,000,000,000)����ʾ��Ҫ�ĸ�������.
//
//
//
//�������:
//
//���������Ҫ���̵깺���������ɫ������ע����ܹ������ɫ��һ����ʹ���ڻ��У�ֻ��Ϊ�˲����µ���ɫ��
//
//
//��������:
//
//3
//1 7 3
//
//
//�������:
//
//3

//˼·������и����ԣ���A xor B=C�����Եõ�A xor C=B, B xor C=A���ٽ�һ���ɵ�A xor B xor C=0
//�ڱ����в�����0��ɫ��ʵ����0��ʾ��ɫ���������������ʿ����޳���Ŀ����ɫ�ж������ɫ�������޳���������ɫ���Ӷ��õ���Ҫ�����������ɫ��
//�����һ�����޳�������ɫ�����⣬��ÿ����ɫ����ÿ����ɫ�򻯳ɶ�����ֻ��1λ1�������Ҳ����ͨ�����������Ŀ����ɫ�����Ʊ����γɵľ������
//����������ȵĹ����в���

#include <iostream>
using namespace std;
void swap(int *p, int *q)
{
	unsigned int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
int getBit(int num, int wei, int bitLen = 32)
{
	//���num�Ķ�����������weiλ������
	//weiΪ�����ڼ�λ
	num = num >> (bitLen - wei) & 1;
//	num = num & 1;
	return num;
}
void printIntBit(int num, int bitLen = 32)
{
//	cout << num << endl;
	for (int i = 1; i <= bitLen; i++)
	{
		cout << getBit(num, i, bitLen);
	}
}
class Matrix
{
public:
	Matrix(int *p, int lenw)
	{
		pColor = p;
		len = lenw;
	}
	int getOrders()
	{
		simplify();
		return calOrders();
	}
	void print()
	{
		for (int i = 0; i < len; i++)
		{
			cout << pColor[i] << " ";
		}
		cout << endl;
	}
	void printBit()
	{
		for (int i = 0; i < len; i++)
		{
			printIntBit(pColor[i]);
			cout << endl;
		}
	}
private:
	int *pColor;
	int bitLen = 32; //��64λ
	int len;
	int getFirst1(int i, int wei)
	{
		//�ӵ�i+11�У��±�i��ʼ���ң����ҳ���һ����weiλΪ1�����������±�
		int w;
		for (; i < len; i++)
		{
			w = getBit(pColor[i], wei);
			if (1 == w)
			{
//				cout<<"i:"<<i<<endl;
//				cout<<"wei:"<<wei<<endl;
//				cout<<"w:"<<w<<endl;
				break;
			}
		}
		//����ֵ����len��ʾû���ҵ����ʵ���
		return i;
	}

	void simplify()
	{
		int rawNum, w, i, j;
		j = 1;
		for (i = 0; i < len; i++)
		{
			for (; j <= bitLen; j++)
			{
				rawNum = getFirst1(i, j);
				if (len != rawNum)
				{
					//�ҵ�����ֵ
//					cout << "rawNum:" << rawNum << endl;
					break;
				}
			}
			if (j > bitLen)
			{
				//i�к������(������i�е�����)��Ϊ0,�˳�ѭ�������ü�������
				break;
			}
			if (i != rawNum)
			{
				swap(pColor[i], pColor[rawNum]);
			}
			for (int k = i + 1; k < len; k++)
			{
				w = getBit(pColor[k], j);
				if (1 == w)
				{
					pColor[k] ^= pColor[i];
				}
			}
//			cout << "in" << endl;
		}
	}
	int calOrders()
	{
		int i;
		for (i = 0; i < len; i++)
		{
			if (0 == pColor[i])
			{
				break;
			}
		}
		return i;
	}
};

int main()
{
	int numOfColor;
	cin >> numOfColor;
	int *pcolors = new int[numOfColor];
	for (int i = 0; i < numOfColor; i++)
	{
		cin >> pcolors[i];
	}

	Matrix m(pcolors, numOfColor);
	cout << m.getOrders() << endl;
//	m.printBit();
//	m.print();
//	printIntBit(6);
//	cout << getBit(2, 32);
	return 0;
}
