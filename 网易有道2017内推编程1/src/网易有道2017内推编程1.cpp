//============================================================================
// Name        : �����е�2017���Ʊ��1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
 ��������:

 ��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��������һ����2n����a1,a2,...,a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�



 �������:

 ����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�


 ��������:

 3
 3 1
 1 2 3 4 5 6
 3 2
 1 2 3 4 5 6
 2 2
 1 1 1 1


 �������:

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
		//*pΪһ���Ƶ�ǰ��λ��,�Ƶ�����
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

