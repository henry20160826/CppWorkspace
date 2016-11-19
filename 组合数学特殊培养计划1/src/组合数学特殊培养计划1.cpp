//============================================================================
// Name        : 组合数学特殊培养计划1.cpp
// Author      : Hu Qinghua
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//解决重集的排列，组合问题，利用容斥原理
//关键：利用容斥原理
#include <iostream>
using namespace std;
void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*p = temp;
}

int getCombanition(int n, int k)
{
	//n个里面取k个
	//经证明乘除同时进行必定能整除
	if (n / 2 < k)
	{
		k = n - k;
	}
	int result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= n - i + 1;
		result /= i;
	}
	return result;
}
int f(int n, int r)
{
	return getCombanition(n + r - 1, r);
}
bool getNextCombination(int *p, int &plen, int klen)
{
	//寻找下一个子集组合
	//返回true表示找到下一个组合，保存在p中，返回false表示找不到新的组合

	//*p的空间长度为len,当前有效值长度为plen，其中的内容为当前使用的内容编号
	//klen表示重集中的不同元素的个数
	//plen==klen时该函数的调用应当停止
	//A集合下标从零开始
	//求下一组集合

	//寻找下一个集合编号组成
	int before = plen - 1;
	while (before >= 0)
	{
		if (p[before] < klen + before - plen)
		{
			p[before]++;
			for (int i = before + 1; i < plen; i++)
			{
				p[i] = p[i - 1] + 1;
			}
			break;
		}
		else
		{
			before--;
		}
	}
	//如果此时before大于0，已经移动，不用再处理
	if (before < 0)
	{
		//需要重置
		if (plen < klen)
		{
			//以无法移动的方式退出，需要将集合数量加一，全部重新设置
			plen++;
			//		cout << "plen加一1" << endl;
			for (int i = 0; i < plen; i++)
			{
				p[i] = i;
			}
		}
		//需要结束
		else
		{
			plen++;
			return false;
		}
	}

//	cout << "p:";
//	for (int i = 0; i < plen; i++)
//	{
//		cout << p[i] << " ";
//	}
//	cout << endl;
	return true;
}
int getCombinationNum(int *p, int &plen, int *k, int klen, int r)
{
	//得到下一个交集的f值，
	//*p的长度为空间长度为len,当前有效值长度为plen，其中的内容为当前使用的集合编号
	//r 表示要取出的值个数
	//*k的长度为len，表示重集中的不同元素的个数
	//plen==klen时该函数的调用应当停止
	//A集合下标从零开始
	//计算此分组取法的组合数量，无效组合返回0
	int sum = 0, rnew;
	for (int i = 0; i < plen; i++)
	{
		if (k[p[i]] == -1)
		{
			//此元素无限多，结束运行
			//cout << "集合无效，还可以计算下一个集合" << endl;
			return 0;
		}
		sum += k[p[i]] + 1;
	}
	rnew = r - sum;
	//cout << "rnew:" << rnew << endl;
	if (rnew >= 0)
	{
		int symbol = 0 < plen % 2 ? -1 : 1;
		return symbol * f(klen, rnew);
	}
	else
	{
		//cout << "集合无效，还可以计算下一个集合" << endl;
		return 0;
	}
}
class RepeatSet
{
//重集
public:

	RepeatSet(int *aw, int *kw, int lenw) :
			a(aw), k(kw), len(lenw)
	{
		//重集的构造函数，a为传入的数字内容，k为其对应的数量，len代表a，k两个数组的长度
		sortOrderByk();//按照k的大小对a，k进行排列。从小到大排列
		count = 0;
		//倒序循环提高效率，尽早查找到无穷多的元素
		for (int i = len - 1; i >= 0; i++)
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
	void print()
	{
		//输出集合内容
		cout << "重集内容为：{";
		for (int i = 0; i < len - 1; i++)
		{
			cout << k[i] << "*" << a[i] << ",";
		}
		cout << k[len - 1] << "*" << a[len - 1];
		cout << "}" << endl;
	}
	int getCounts(int num)
	{
		//得到重集中某元素num的数量
		for (int i = 0; i < len; i++)
		{
			if (a[i] == num)
			{
				//返回-1时表示此元素有无穷多个
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
		//得到重集中总的元素个数
		return count;
	}
	int getRCombination(int r)
	{
		int plen = 0;
		int *p = new int[len]();
		int result = f(len, r);
		while (getNextCombination(p, plen, len))
		{
			result += getCombinationNum(p, plen, k, len, r);
		}
		return result;
	}
private:
	int len; //集合中不同元素种数
	int *a; //不同的元素
	int *k; //相同元素的个数,-1表示对应元素有无穷个
	int count; //总体元素个数
	void sortOrderByk()//参照k从小到大排列
	{
		int i, j, min;
		for (i = 0; i < len; i++)
		{
			min = i;
			for (j = i + 1; j < len; j++)
			{
				if (k[min] > k[j] && k[j] != -1)
				{
					min = j;
				}
				else if (-1 == k[min] && k[j] != -1)
				{
					min = j;
				}
			}
			if (min != i)
			{
				swap(k[i], k[min]);
				swap(a[i], a[min]);
			}
		}
	}
};

int main()
{
#define N 4
	int len = N;
	int a[] =
	{ 2, 4, 8, 3 }; //a在实际计算中没有使用
	int k[] =
	{ 4, 3, -1, 4 };
	RepeatSet set(a, k, len);
	set.print();
	cout << endl << "result:" << set.getRCombination(12) << endl;
	cout << endl << "result:" << set.getRCombination(4) << endl;
	return 0;
}
