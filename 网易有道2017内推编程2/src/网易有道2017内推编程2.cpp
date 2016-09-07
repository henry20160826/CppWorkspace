//============================================================================
// Name        : �����е�2017���Ʊ��2.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//С��ͬѧ��1��n��n�����ְ���һ����˳�������һ������Q�С��������Զ���Qִ�������³���
//
//while(!Q.empty())              //���в��գ�ִ��ѭ��
//
//{
//
//    int x=Q.front();            //ȡ����ǰ��ͷ��ֵx
//
//    Q.pop();                 //������ǰ��ͷ
//
//    Q.push(x);               //��x�����β
//
//    x = Q.front();              //ȡ����ʱ���ͷ��ֵ
//
//    printf("%d\n",x);          //���x
//
//    Q.pop();                 //������ʱ��Ķ�ͷ
//
//}
//
//��ȡ����ͷ��ֵ������ʱ�򣬲���������ǰ��ͷ��
//С��ͬѧ���֣���γ���ǡ�ð�˳�������1,2,3,...,n������С�������㹹���ԭʼ�Ķ��У�����������[ע��ԭ������������5�д�Ӧ��Ϊ3������������]
//��������:
//
//��һ��һ������T��T �� 100����ʾ����������ÿ����������һ����n��1 �� n �� 100000�������������n֮�Ͳ�����200000��
//
//
//
//�������:
//
//����ÿ�����ݣ����һ�У���ʾԭʼ�Ķ��С�����֮����һ���ո��������Ҫ����ĩ�������Ŀո�.
//
//
//��������:
//
//4
//1
//2
//3
//10
//
//
//�������:
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
				//�ճ�һ��λ�ã���Ϊ�����Ҫ����������β
				keep++;
				i++;
				i %= len;
			}
			if (1 == keep && 0 == p[i])
			{
				//�ҵ����ʵ�λ�ã���������
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
