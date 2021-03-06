//============================================================================
// Name        : 中兴机试周鸣1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//非抢占式SJF
void swap(int *p, int *q)
{
	//交换时需要传入地址
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void print(int *requesTimes, int *durations, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << requesTimes[i] << " " << durations[i] << endl;
	}
}
int getFirstProcess(int *requesTimes, int n, int start = 0)
{
	//返回请求时间最早的进程号
	int min = start;
	for (int i = start + 1; i < n; i++)
	{
		if (requesTimes[i] < requesTimes[min])
		{
			min = i;
		}
	}
	return min;
}
int getNextProcess(int *requesTimes, int *durations, int start, int n, int time)
{
	int min = -1;
	int i = start;
	//查找请求时间合适的进程
	for (; i < n; i++)
	{
		if (requesTimes[i] <= time)
		{
			min = i;
			break;
		}
	}
	if (i == n)
	{
		//没找到时间和适合进程，此时CPU有空闲时间。
		//找出接下来请求时间最早的进程
		min = getFirstProcess(requesTimes, n, start);
	}
	else
	{
		//找到合适进程，此时
		for (; i < n; i++)
		{
			//请求时间在当前任务结束之前，且是这段时间中最短的进程
			if (requesTimes[i] < time && durations[i] < durations[min])
			{
				min = i;
			}
			if (durations[i] == durations[min]
					&& requesTimes[i] < requesTimes[min])
			{
				min = i;
			}
		}
	}
	return min;
}
float avgWaitTime(int *requesTimes, int *durations, int n)
{
	int min, waitTime = 0;
	//寻找第一个进程
	min = getFirstProcess(requesTimes, n);
	if (0 != min)
	{
		swap(requesTimes + min, requesTimes);
		swap(durations + min, durations);
	}

	int time = requesTimes[0] + durations[0];
//	print(requesTimes, durations, n);
	//寻找下一个进程
	for (int i = 1; i < n; i++)
	{
		min = getNextProcess(requesTimes, durations, i, n, time);
//		cout << "min" << min << endl;
		if ((i != min) && (min != -1))
		{
			swap(requesTimes + min, requesTimes + i);
			swap(durations + min, durations + i);
		}

//		//测试用输出
//		print(requesTimes, durations, n);
//		cout << "i:" << i << endl;
//		cout << time - requesTimes[i] << endl;
//		print(requesTimes, durations, n);
		if (time > requesTimes[i])
		{
			//CPU无空闲状态
			waitTime += time - requesTimes[i];
			time += durations[i];
		}
		else
		{
			//CPU空闲状态
			//等待时间无变化
			time = requesTimes[i] + durations[i];
		}

	}
	cout << "sum of waiTime" << waitTime << endl;
	float w = (float) waitTime;
	float aveWaitTime = w / n;
	return aveWaitTime;
}

int main()
{
#define N 5
	int requesTimes[N] =
	{ 5, 3, 4, 1, 2 };
	int durations[N] =
	{ 5, 3, 4, 1, 2 };
	cout << avgWaitTime(requesTimes, durations, N);
	return 0;
}
