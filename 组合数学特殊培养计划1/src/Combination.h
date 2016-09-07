/*
 * Combination.h
 *
 *  Created on: 2016-8-14
 *      Author: Administrator
 */

#ifndef COMBINATION_H_
#define COMBINATION_H_

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
class Combination
{
	friend void print(int *p, int n);
public:
	Combination(int*pw, int lenw, int chosenNumw) :
			p(pw), len(lenw), chosenNum(chosenNumw)
	{
	}
	int getCombinationNum() //calculate arrangement
	{
		int r = 1;
		for (int i = len; i > len - chosenNum; i--)
		{
			r *= i;
		}
		for (int i = 2; i <= chosenNum; i++)
		{
			r /= i;
		}
		return r;
	}
	bool getNextCombination()
	{
		//0 to chosenNum-1 is chosen
		int i, j;
		for (i = chosenNum - 1; i >= 0; i--)
		{
			for (j = chosenNum; j < len; j++)
			{
				if (p[i] < p[j])
				{
					int t;
					t = p[i];
					p[i] = p[j];
					p[j] = t;
					i++;
					std::sort(p + i, p + len);
//					std::cout << "after sort:";
//					print(p, len);
					j = getPositon(i - 1);
					while (i < chosenNum && j < len)
					{
						t = p[i];
						p[i] = p[j];
						p[j] = t;
						i++;
						j++;
					}
					std::sort(p + chosenNum, p + len);
					return true;
				}
			}
		}
		return false;
	}

	int printAllCombination()
	{
		int n = 0;
		do
		{
			print(p, chosenNum);
			//		print(p, chosenNum);
			n++;
		} while (getNextCombination());
		return n;
	}
private:
	int *p;
	int len;
	int chosenNum;
	int getPositon(int i)
	{
		int num = p[i];
		i++;
		for (; p[i] < num; i++);
		return i;
	}
};

#endif /* COMBINATION_H_ */
