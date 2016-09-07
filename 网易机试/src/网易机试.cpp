//============================================================================
// Name        : ���׻���.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//��Ŀ��
//ţţ����ҵ������һ������Ϊn������A,������а����˴�1��n��n������������ΪһЩԭ��������һЩλ�ã�������10�����������ˣ�
//����ţţ�ǵ��������˳��Ե�������k,˳�����ָ����i<j��A[i]<A[j]�Ķ����������ţţ��������������Ҫ��ĺϷ�������Ŀ������n,k������A,���ؿ��ܵĴ���������Ŀ��
//����������
//ÿ���������һ������������ÿ�����������ĵ�һ�а�����������n��k��1<=n<=100��1<=k<=1000000000����
//��������һ�У�����n�����ֱ�ʾ����A�����е���0�����ʾ�������λ�ã�������10������
//���������
//���һ�б�ʾ�Ϸ����е���Ŀ��
//�������ӣ�
//5 5
//4 0 0 2 0
//������ӣ�
//2
#include <iostream>
#include <algorithm>
using namespace std;
void printBase(int *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
}
void printBase(bool *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
}
int getAfterCouple(int i, int *pa, int paLen)
{
	int couple = 0;
	int *p = pa + i;
	pa = p++;
	for (int j = i + 1; j < paLen; j++, pa++)
	{
		if (*pa > *p)
		{
			couple++;
		}
	}
	return couple;
}
int getCouple(int numNow, int *pa, int paLen)
{
	int couple = 0;
	for (int j = 0; j < paLen; j++, pa++)
	{
		if (*pa > numNow)
		{
			couple++;
		}
	}
	return couple;
}
int getCouple(int *pa, int paLen, int *pb, int pbLen)
{
	int couple = 0;
	for (int i = 0; i < paLen; i++, pa++)
	{
		couple += getCouple(*pa, pb, pbLen);
	}
	return couple;
}
class LostList
{
public:
	LostList(int *pb, int pbLen)
	{
		len = *pb;
		num = new int[len]();
		int *p = num;
		pb++;
		for (int i = 1; i < pbLen; i++, pb++)
		{
			if (0 == *pb)
			{
				*p = i;
				p++;
			}
		}
	}
	int *num;
	int len;
	void print()
	{
		printBase(num, len);
	}
	void printArrangement()
	{
		do
		{
			print();
		} while (getNextArrangment());
	}
	void sortSelf()
	{
		sort(num, num + len);
	}
private:
	bool getNextArrangment()
	{
		int min, i;
		bool flag = false;
		for (i = len - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < len; j++)
			{

				if (!flag && num[j] > num[i])
				{
					min = j;
					flag = true;
				}
				if (flag && num[j] > num[i] && num[j] < num[min])
				{
					min = j;
				}
			}
			if (flag)
			{
				int temp = num[i];
				num[i] = num[min];
				num[min] = temp;
				sort(num + i + 1, num + len);
				return true;
			}
		}
		return false;
	}
};
class Lists
{
public:
	Lists(int *pa, int paLen)
	{
		createNULL(paLen);
		int numNow;
		bool typeNow = *pa > 0 ? true : false;
		for (int i = 0; i < paLen;)
		{
			numNow = *(pa + i);
			types[len] = typeNow;
			if (typeNow) //a series of normal number
			{
				heads[len] = i;

				while (numNow > 0 && i < paLen)
				{
					*(pb + numNow) = 1;
					coupleNow += getAfterCouple(i, pa, paLen);
					i++;
					numNow = *(pa + i);
				}
			}
			else //a series of zero
			{
				heads[len] = i;
				while (0 == numNow && i < paLen)
				{
					(*pb)++; //count plus
					i++;
					numNow = *(pa + i);
				}
			}
			typeNow = !typeNow;
			len++;
		}
		heads[len] = paLen;
		pbLen = paLen + 1;
	}
	void createNULL(int paLen)
	{
		heads = new int[12];
		types = new bool[11];
		len = 0;
		coupleNow = 0;
		pb = new int[paLen + 1]();
		pbLen = 0;
	}
	int *pb;
	int pbLen;
	int *heads;
	bool *types; //0 is lost,1 is normal
	int len;
	int coupleNow;
	void printHeads()
	{
		printBase(heads, len + 1);
	}
	void printTypes()
	{
		printBase(types, len);
	}
};
class XArray
{
public:
	XArray(int *paw, int paLenw, int kw)
	{
		pa = paw;
		paLen = paLenw;
		k = kw;
		lists = new Lists(pa, paLen);
		lostlist = new LostList(lists->pb, paLen + 1);
		coupleIheret = getCoupleIheret();
		coupleLost = k - lists->coupleNow - coupleIheret;
	}
	Lists *lists;
	LostList *lostlist;
	int coupleIheret;
	int coupleLost;

private:
	int *pa;
	int paLen;
	int k;
	int getCoupleIheret()
	{
		int couple = 0;

		if (lists->types[0])
		{
			couple = getCouple(pa, lists->heads[1], lostlist->num,
					lostlist->len);
//			cout << couple << endl;
		}
		if (lists->types[lists->len - 1])
		{
			couple += getCouple(lostlist->num, lostlist->len,
					pa + lists->heads[lists->len - 1],
					lists->heads[lists->len] - lists->heads[lists->len - 1]);
//			cout<<"len:"<<lists->heads[lists->len]<<endl;
//			cout<<lists->heads[lists->len-1]<<endl;
//			print(lostlist->num, lostlist->len);
//			print(pa + lists->heads[lists->len - 1],
//					lists->heads[lists->len] - lists->heads[lists->len - 1]);
		}

		return couple;
	}
};
int arrangement(int n) //calculate arrangement
{
	int r = 1;
	for (int i = 2; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
int sum(int n) //calculate max alone couple
{
	int sum = 0;
//	n--;
	for (int i = 1; i < n; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	cout << "Hello World" << endl; // prints Hello World

//	k is count of couples
//	n is count of numbers
	int n, k;
	k = 5;
	n = 5;
//	cin >> n >> k;
	int *pa = new int[n]
	{ 4, 0, 0, 2, 0 };

	XArray *xarray = new XArray(pa, n, k);
//	cout << "coupleNow:" << xarray->lists->coupleNow << endl;
//	print(xarray->lists->pb, xarray->lists->pbLen);
//	print(xarray->lists->heads, xarray->lists->len + 1);
//	print(xarray->lists->types, xarray->lists->len);
//	print(xarray->lostlist->num, xarray->lostlist->len);
//	cout << "coupleLost:" << xarray->coupleLost << endl;
	xarray->lostlist->printArrangement();
//analyze externality
//inherent externality
//head
//optional externality

	return 0;
}
