//============================================================================
// Name        : alg.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class interval
{
public:
	interval()
	{
		startTime = 0;
		endTime = 0;
	}
	interval(int s, int e)
	{
		set(s, e);
	}
	void set(int s, int e)
	{
		startTime = s;
		endTime = e;
	}
	int startTime;
	int endTime;
private:
};
class Cmp
{
public:
	bool operator()(const interval &t1, const interval &t2)
	{
		if (t1.endTime < t2.endTime)
		{
			return true;
		}
		return false;
	}
};
#define N 8
int main()
{
	//��ֵ
	int startTime[N] =
	{ 0, 1, 3, 3, 4, 5, 6, 8 };
	int endTime[N] =
	{ 6, 4, 5, 8, 7, 9, 10, 11 };
	vector<interval> v;
	for (int i = 0; i < 8; ++i)
	{
		v.push_back(interval(startTime[i], endTime[i]));
	}
	//������ʱ�������˳��������������
	sort(v.begin(), v.end(), Cmp());
	vector<interval> rv;
	//ѡ������ѡ�������ͻ�Ľ���ʱ�����������
	//1.������ѡ�����ͻ
	//2.����ʱ������
	rv.push_back(v[0]);
	v.erase(v.begin());
	int len = v.size();
	int i = 0, j = 0;
	for (; i < len; ++i)
	{
		//�ж��Ƿ��ͻ
		if (v[i].startTime < rv[j].endTime)
		{
			//��ͻ,�Թ����ѡ��
		}
		else
		{
			//�ҵ���һ������ͻ������
			//����
			rv.push_back(v[i]);
			++j;
		}
	}
	//������
	len = rv.size();
	for (int i = 0; i < len; ++i)
	{
		cout << rv[i].startTime << " " << rv[i].endTime << endl;
	}
	return 0;
}