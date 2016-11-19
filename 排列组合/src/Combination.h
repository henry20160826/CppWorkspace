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
void print(int *p, int n); //����������ʡ��
class Combination
{
	friend void print(int *p, int n);
public:
	Combination(int*pw, int lenw, int chosenNumw) :
			p(pw), len(lenw), chosenNum(chosenNumw)
	{
		std::sort(p, p + len);
		chosenSN = new int[chosenNum]();
	}
	int getCombinationNum() //calculate arrangement
	{
		int k = chosenNum;
		if (len / 2 < k)
		{
			k = len - k;
		}
		int r = 1;
		for (int i = 1; i <= k; i--)
		{
			r *= len - i + 1;
			r /= i;
		}
		return r;
	}
	bool getNextCombination(bool isFirst = false)
	{
////		�ɰ�
////		0 to chosenNum-1 is chosen
//		int i, j;
//		for (i = chosenNum - 1; i >= 0; i--)
//		{
//			for (j = chosenNum; j < len; j++)
//			{
//				if (p[i] < p[j])
//				{
//					int t;
//					t = p[i];
//					p[i] = p[j];
//					p[j] = t;
//					i++;
//					std::sort(p + i, p + len);
////					std::cout << "after sort:";
////					print(p, len);
//					j = getPositon(i - 1);
//					while (i < chosenNum && j < len)
//					{
//						t = p[i];
//						p[i] = p[j];
//						p[j] = t;
//						i++;
//						j++;
//					}
//					std::sort(p + chosenNum, p + len);
//					return true;
//				}
//			}
//		}
//		return false;

		//�°� Ч�ʱȾɰ�õö�
		//Ѱ����һ�����ϱ�����
		//��һ����Ҫ������ʼ��
		if (isFirst)
		{
			for (int i = 0; i < chosenNum; i++)
			{
				chosenSN[i] = i;
			}
		}
		int before = chosenNum - 1;
		while (before >= 0)
		{
			if (chosenSN[before] < len + before - chosenNum)
			{
				chosenSN[before]++;
				for (int i = before + 1; i < chosenNum; i++)
				{
					chosenSN[i] = chosenSN[i - 1] + 1;
				}
				break;
			}
			else
			{
				before--;
			}
		}
		//�����ʱbefore����0���Ѿ��ƶ��������ٴ���
		if (before < 0)
		{
			return false;
		}
		return true;
	}

	int printAllCombination()
	{
		int n = 0;
		while (getNextCombination())
		{
			printP();
			//		print(p, chosenNum);
			n++;
		}
		return n;
	}
private:
	int *p;
	int len;
	int chosenNum;
	int *chosenSN;
	void printP()
	{
		for (int i = 0; i < chosenNum; i++)
		{
			std::cout << p[chosenSN[i]] << " ";
		}
		std::cout << std::endl;
	}
//	int getPositon(int i)
//	{
//		int num = p[i];
//		i++;
//		for (; p[i] < num; i++)
//			;
//		return i;
//	}
};

#endif /* COMBINATION_H_ */
