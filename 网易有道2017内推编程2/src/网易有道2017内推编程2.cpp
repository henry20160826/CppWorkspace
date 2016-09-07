//============================================================================
// Name        : 网易有道2017内推编程2.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
//
//while(!Q.empty())              //队列不空，执行循环
//
//{
//
//    int x=Q.front();            //取出当前队头的值x
//
//    Q.pop();                 //弹出当前队头
//
//    Q.push(x);               //把x放入队尾
//
//    x = Q.front();              //取出这时候队头的值
//
//    printf("%d\n",x);          //输出x
//
//    Q.pop();                 //弹出这时候的队头
//
//}
//
//做取出队头的值操作的时候，并不弹出当前队头。
//小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？[注：原题样例第三行5有错，应该为3，以下已修正]
//输入描述:
//
//第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。
//
//
//
//输出描述:
//
//对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.
//
//
//输入例子:
//
//4
//1
//2
//3
//10
//
//
//输出例子:
//
//1
//2 1
//2 1 3
//8 1 6 2 10 3 7 4 9 5

#include <iostream>
using namespace std;
class Queue
{
public:
	Queue(int lenw)
	{
		len = lenw;
		p = new int[len]();
		int count = 1;
		int i = 0;
		int keep = 0;
		while (count <= len)
		{
			if (0 == keep && (0 == p[i] || p[i] > count))
			{
				//空出一个位置，因为这个数要被调整到队尾
				keep++;
				i++;
				i %= len;
			}
			if (1 == keep && 0 == p[i])
			{
				//找到合适的位置，插入数字
				p[i] = count;
				count++;
				keep = 0;
			}
			i++;
			i %= len;
		}
	}
	void print()
	{
		for (int i = 0; i < len - 1; i++)
		{
			cout << p[i] << " ";
		}
		cout << p[len - 1] << endl;
	}
private:
	int len;
	int *p;
}
;
int main()
{
	int times;
	cin >> times;
	int *plen = new int[times];
	for (int i = 0; i < times; i++)
	{
		cin >> plen[i];
	}
	for (int i = 0; i < times; i++)
	{
		Queue queue(plen[i]);
		queue.print();
	}
	delete[] plen;
	return 0;
}
