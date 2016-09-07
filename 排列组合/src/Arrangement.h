/*
 * Arrangement.h
 *
 *  Created on: 2016-8-14
 *      Author: Administrator
 */

#ifndef ARRANGEMENT_H_
#define ARRANGEMENT_H_

//#ifndef BASE_H_
//#define BASE_H_
//#include "Base.h"
//#endif

#ifndef ALGORITHM
#define ALGORITHM
#include <algorithm>
#endif

#include "Base.h"
//#include <algorithm>
//function print in Base.h
void print(int *p, int n); //此声明不能省略
class Arrangement
{
	friend void print(int *p, int n);
public:
	//构造函数
	Arrangement(int *pw, int lenw) :
			p(pw), len(lenw)
	{
	}
	int getArrangementNum() //calculate arrangement
	{
		int r = 1;
		for (int i = 2; i <= len; i++)
		{
			r *= i;
		}
		return r;
	}
	bool getNextAllArrangment()
	{
		int min, i;
		bool flag = false;
		for (i = len - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < len; j++)
			{

				if (!flag && p[j] > p[i])
				{
					min = j;
					flag = true;
				}
				if (flag && p[j] > p[i] && p[j] < p[min])
				{
					min = j;
				}
			}
			if (flag)
			{
				int temp = p[i];
				p[i] = p[min];
				p[min] = temp;
				std::sort(p + i + 1, p + len);
				return true;
			}
		}
		return false;
	}
	int printAllArrangement()
	{
		std::sort(p, p + len);
		int n = 0;
		do
		{
			print(p, len);
			n++;
		} while (getNextAllArrangment());
		return n;
	}
private:
	int *p;
	int len;
//	void print(int *p, int n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			std::cout << *(p + i) << " ";
//		}
//		std::cout << std::endl;
//	}
};

#endif /* ARRANGEMENT_H_ */
