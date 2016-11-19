//============================================================================
// Name        : ÷‹√˘Ã⁄—∂ª˙ ‘2.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int getMaxFloor(int ball, int time)
{
	if (1 == time)
	{
		return 1;
	}
	if (1 == ball)
	{
		return time;
	}
	return getMaxFloor(ball - 1, time - 1) + 1 + getMaxFloor(ball, time - 1);

}
int getMinTime(int ball, int floor)
{
	int len = ball - 1;
	int *toWhere = new int[len];
	int time = 1;
	for (int i = 0; i < len; i++)
	{
		toWhere[i] = 1;
	}
	int temp1 = 1;
	int temp2;
	while (toWhere[len - 1] < floor)
	{
		for (int i = 0; i < len; i++)
		{
			if (0 == i)
			{
				temp1 = toWhere[i];
				toWhere[i] = time + 1 + toWhere[i];
			}
			else
			{
//				cout << "temp:" << temp << ",towhere" << toWhere[i] << endl;
				temp2 = toWhere[i];
				toWhere[i] = temp1 + 1 + toWhere[i];
				temp1 = temp2;
			}

		}
		time++;
//		for (int i = 0; i < len; i++)
//		{
//			cout << toWhere[i] << " ";
//		}
//		cout << endl;
	}
	return time;

}
int getMinBall(int floor, int time)
{
	if (time >= floor)
	{
		return 1;
	}
	int *p1 = new int[time];
	int *p2 = new int[time];
	int *temp;
	int ball = 3;
	p1[0] = 1;
	p2[0] = 1;
	for (int i = 1; i < time; i++)
	{
		p1[i] = p1[i - 1] + i + 1;
		p2[i] = p1[i - 1] + 1 + p2[i - 1];
	}
	if (p1[time - 1] >= floor)
	{
		return 2;
	}
	if (p2[time - 1] >= floor)
	{
		return 3;
	}

	while (p2[time - 1] < floor)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
		for (int i = 1; i < time; i++)
		{
			p2[i] = p1[i - 1] + 1 + p2[i - 1];
		}
//		for (int i = 1; i < time; i++)
//		{
//			cout << p2[i] << " ";
//		}
//		cout << endl;
		ball++;
//		cout << ball << endl;
	}
//	cout << "p2[time - 1]: " << p2[time - 1] << endl;
	return ball;
}
int main()
{
	cout << getMaxFloor(5, 7) << endl;
	cout << getMinTime(3, 92) << endl;
	cout << getMinBall(98, 7) << endl;
	return 0;
}
