//============================================================================
// Name        : 刘贤娇京东机试1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int* getKinds(string s[], int len)
{
	//处理购物清单，将购物清单中重复的条目合并
	//返回一个数组，数组长度与购物清单一样长（因为可能没有重复的物品），数组中的一个值表示一种物品的数量，多余部分为0
	int i, j;
	int *kinds = new int[len]();
	kinds[0] = 1;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (s[i] == s[j])
			{
				break;
			}
		}
		kinds[j]++;
	}
	return kinds;
}

int main()
{
//	cout << "Hello World" << endl; // prints Hello World
	int label;
	int buys;

	while (1)
	{
		//输入标签数量，购物清单条目数量
		cin >> label >> buys;
		//输入标签内容
		int *price = new int[label];
		for (int i = 0; i < label; i++)
		{
			cin >> price[i];
		}
		//输入购物清单
		//使用string有可能降低效率，改为字符串可能会提高效率
		string *list = new string[buys];
		for (int i = 0; i < buys; i++)
		{
			cin >> list[i];
		}
		//处理购物清单，将重复内容合并
		int *kinds = getKinds(list, buys);
		//对购物清单排序（从小到大）
		sort(kinds, kinds + buys);
		//对标签排序（从小到大）
		sort(price, price + label);

//	for (int i = 0; i < buys; i++)
//	{
//		cout << kinds[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < label; i++)
//	{
//		cout << price[i] << " ";
//	}
//	cout << endl;

		int min = 0, max = 0;
		for (int i = 0; i < buys; i++)
		{
			if (0 == kinds[buys - i - 1])
			{
				//购买数量已经为0，退出循环
				//缩短循环次数，不然可能超时
				break;
			}
			//使数量最多的物品价格最低，从而预算最低
			min += kinds[buys - i - 1] * price[i];
			//使数量最多的物品价格最高，从而预算最高
			max += kinds[buys - i - 1] * price[label - i - 1];
		}
		cout << min << " " << max;
	}
	return 0;
}
