//============================================================================
// Name        : 组合数学特殊培养计划1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//解决重集的排列，组合问题，利用容斥原理
//关键：利用容斥原理
#include <iostream>
using namespace std;

class RepeatSet
{
	//重集
public:
	RepeatSet(int *aw, int *kw, int lenw)
	{
		len = lenw;
		a = aw;
		k = kw;
		count = 0;
		for (int i = 0; i < len; i++)
		{
			if (k[i] != -1)
			{
				count += k[i];
			}
			else
			{
				count = -1; //表示重集中有无穷多的元素
				break;
			}
		}
	}
	int getCounts(int num)
	{
		//得到重集中元素num的数量
		for (int i = 0; i < len; i++)
		{
			if (a[i] == num)
			{
				return k[i];
			}
		}
		return -2; //返回-2表示找不到该元素
	}
	int getKindNum()
	{
		//得到重集中有多少不同元素
		return len;
	}
	int getCountNum()
	{
		return count;
	}
private:
	int len; //集合中不同元素种数
	int *a; //不同的元素
	int *k; //相同元素的个数,-1表示对应元素有无穷个
	int count; //总体元素个数
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
