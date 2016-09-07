//============================================================================
// Name        : 网易2017内推笔试编程题合集（二）画家问题.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，我们用正整数表示不同颜色的颜料。你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？
//输入描述:
//
//第一行为绘制这幅画需要的颜色种数n (1 ≤ n ≤ 50)
//第二行为n个数xi(1 ≤ xi ≤ 1,000,000,000)，表示需要的各种颜料.
//
//
//
//输出描述:
//
//输出最少需要在商店购买的颜料颜色种数，注意可能购买的颜色不一定会使用在画中，只是为了产生新的颜色。
//
//
//输入例子:
//
//3
//1 7 3
//
//
//输出例子:
//
//3

//思路：异或有个特性，若A xor B=C，可以得到A xor C=B, B xor C=A，再进一步可得A xor B xor C=0
//在本题中不存在0颜色（实际中0表示黑色），利用上述性质可以剔除掉目标颜色中多余的颜色，不断剔除掉多余颜色，从而得到需要购买的最少颜色。
//会出现一个该剔除哪种颜色的问题，简化每种颜色，将每种颜色简化成二级制只有1位1的情况。也就是通过异或运算求目标颜色二进制编码形成的矩阵的秩
//矩阵异或求秩的过程中不会

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
	//获得num的二进制左数第wei位的数字
	//wei为左数第几位
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
	int bitLen = 32; //或64位
	int len;
	int getFirst1(int i, int wei)
	{
		//从第i+11行（下标i开始查找），找出第一个第wei位为1的数，返回下标
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
		//返回值等于len表示没有找到合适的行
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
					//找到非零值
//					cout << "rawNum:" << rawNum << endl;
					break;
				}
			}
			if (j > bitLen)
			{
				//i行后的内容(包括第i行的内容)都为0,退出循环，不用继续化简
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
