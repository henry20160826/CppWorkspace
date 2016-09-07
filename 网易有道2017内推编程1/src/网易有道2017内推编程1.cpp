//============================================================================
// Name        : 网易有道2017内推编程1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
 输入描述:

 第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。



 输出描述:

 对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。


 输入例子:

 3
 3 1
 1 2 3 4 5 6
 3 2
 1 2 3 4 5 6
 2 2
 1 1 1 1


 输出例子:

 1 4 2 5 3 6
 1 5 4 3 2 6
 1 1 1 1*/

//http://www.nowcoder.com/test/question/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?pid=2385858&tid=4399064
#include <iostream>
using namespace std;
void swap2(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
class Poker
{
public:
	int *card;
	Poker(int *cardw, int lenw)
	{
		card = cardw;
		len = lenw;
		serial = new int[len];
		for (int i = 0; i < len; i++)
		{
			serial[i] = i;
		}
	}
	void print()
	{
		for (int i = 0; i < len - 1; i++)
		{
			cout << *(card + i) << " ";
		}
		cout << *(card + len - 1) << endl;
	}
	void wash(int k = 1)
	{
		//*p为一张牌当前的位置,牌的数量
		int n = len / 2;
		while (k > 0)
		{
			for (int i = 0; i < len; i++)
			{
				if (serial[i] < n)
				{
					serial[i] = serial[i] * 2;
				}
				else
				{
					serial[i] = (serial[i] - n) * 2 + 1;
				}
			}
			k--;
		}
		swap();
	}

private:
	int len;
	int *serial;
	void swap()
	{
		int i, j;
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)
			{
				if (*(serial + j) == i)
				{
					swap2(&card[i], &card[j]);
					swap2(&serial[i], &serial[j]);
					break;
				}
			}
		}
	}
};

int main()
{
	int times = 0;
	cin >> times;
	int *np = new int[times];
	int *washtimes = new int[times];
	int *lenp = new int[times];
	int **p = new int*[times];
	for (int i = 0; i < times; i++)
	{
		cin >> np[i] >> washtimes[i];
		lenp[i] = np[i] * 2;
		p[i] = new int[lenp[i]];
		for (int j = 0; j < lenp[i]; j++)
		{
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < times; i++)
	{
		Poker poker(p[i], lenp[i]);
		poker.wash(washtimes[i]);
		poker.print();
		delete[] p[i];
	}

	return 0;
}

