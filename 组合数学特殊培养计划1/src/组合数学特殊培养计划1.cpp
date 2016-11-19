//============================================================================
// Name        : �����ѧ���������ƻ�1.cpp
// Author      : Hu Qinghua
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//����ؼ������У�������⣬�����ݳ�ԭ��
//�ؼ��������ݳ�ԭ��
#include <iostream>
using namespace std;
void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*p = temp;
}

int getCombanition(int n, int k)
{
	//n������ȡk��
	//��֤���˳�ͬʱ���бض�������
	if (n / 2 < k)
	{
		k = n - k;
	}
	int result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= n - i + 1;
		result /= i;
	}
	return result;
}
int f(int n, int r)
{
	return getCombanition(n + r - 1, r);
}
bool getNextCombination(int *p, int &plen, int klen)
{
	//Ѱ����һ���Ӽ����
	//����true��ʾ�ҵ���һ����ϣ�������p�У�����false��ʾ�Ҳ����µ����

	//*p�Ŀռ䳤��Ϊlen,��ǰ��Чֵ����Ϊplen�����е�����Ϊ��ǰʹ�õ����ݱ��
	//klen��ʾ�ؼ��еĲ�ͬԪ�صĸ���
	//plen==klenʱ�ú����ĵ���Ӧ��ֹͣ
	//A�����±���㿪ʼ
	//����һ�鼯��

	//Ѱ����һ�����ϱ�����
	int before = plen - 1;
	while (before >= 0)
	{
		if (p[before] < klen + before - plen)
		{
			p[before]++;
			for (int i = before + 1; i < plen; i++)
			{
				p[i] = p[i - 1] + 1;
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
		//��Ҫ����
		if (plen < klen)
		{
			//���޷��ƶ��ķ�ʽ�˳�����Ҫ������������һ��ȫ����������
			plen++;
			//		cout << "plen��һ1" << endl;
			for (int i = 0; i < plen; i++)
			{
				p[i] = i;
			}
		}
		//��Ҫ����
		else
		{
			plen++;
			return false;
		}
	}

//	cout << "p:";
//	for (int i = 0; i < plen; i++)
//	{
//		cout << p[i] << " ";
//	}
//	cout << endl;
	return true;
}
int getCombinationNum(int *p, int &plen, int *k, int klen, int r)
{
	//�õ���һ��������fֵ��
	//*p�ĳ���Ϊ�ռ䳤��Ϊlen,��ǰ��Чֵ����Ϊplen�����е�����Ϊ��ǰʹ�õļ��ϱ��
	//r ��ʾҪȡ����ֵ����
	//*k�ĳ���Ϊlen����ʾ�ؼ��еĲ�ͬԪ�صĸ���
	//plen==klenʱ�ú����ĵ���Ӧ��ֹͣ
	//A�����±���㿪ʼ
	//����˷���ȡ���������������Ч��Ϸ���0
	int sum = 0, rnew;
	for (int i = 0; i < plen; i++)
	{
		if (k[p[i]] == -1)
		{
			//��Ԫ�����޶࣬��������
			//cout << "������Ч�������Լ�����һ������" << endl;
			return 0;
		}
		sum += k[p[i]] + 1;
	}
	rnew = r - sum;
	//cout << "rnew:" << rnew << endl;
	if (rnew >= 0)
	{
		int symbol = 0 < plen % 2 ? -1 : 1;
		return symbol * f(klen, rnew);
	}
	else
	{
		//cout << "������Ч�������Լ�����һ������" << endl;
		return 0;
	}
}
class RepeatSet
{
//�ؼ�
public:

	RepeatSet(int *aw, int *kw, int lenw) :
			a(aw), k(kw), len(lenw)
	{
		//�ؼ��Ĺ��캯����aΪ������������ݣ�kΪ���Ӧ��������len����a��k��������ĳ���
		sortOrderByk();//����k�Ĵ�С��a��k�������С���С��������
		count = 0;
		//����ѭ�����Ч�ʣ�������ҵ�������Ԫ��
		for (int i = len - 1; i >= 0; i++)
		{
			if (k[i] != -1)
			{
				count += k[i];
			}
			else
			{
				count = -1; //��ʾ�ؼ�����������Ԫ��
				break;
			}
		}

	}
	void print()
	{
		//�����������
		cout << "�ؼ�����Ϊ��{";
		for (int i = 0; i < len - 1; i++)
		{
			cout << k[i] << "*" << a[i] << ",";
		}
		cout << k[len - 1] << "*" << a[len - 1];
		cout << "}" << endl;
	}
	int getCounts(int num)
	{
		//�õ��ؼ���ĳԪ��num������
		for (int i = 0; i < len; i++)
		{
			if (a[i] == num)
			{
				//����-1ʱ��ʾ��Ԫ����������
				return k[i];
			}
		}
		return -2; //����-2��ʾ�Ҳ�����Ԫ��
	}
	int getKindNum()
	{
		//�õ��ؼ����ж��ٲ�ͬԪ��
		return len;
	}
	int getCountNum()
	{
		//�õ��ؼ����ܵ�Ԫ�ظ���
		return count;
	}
	int getRCombination(int r)
	{
		int plen = 0;
		int *p = new int[len]();
		int result = f(len, r);
		while (getNextCombination(p, plen, len))
		{
			result += getCombinationNum(p, plen, k, len, r);
		}
		return result;
	}
private:
	int len; //�����в�ͬԪ������
	int *a; //��ͬ��Ԫ��
	int *k; //��ͬԪ�صĸ���,-1��ʾ��ӦԪ���������
	int count; //����Ԫ�ظ���
	void sortOrderByk()//����k��С��������
	{
		int i, j, min;
		for (i = 0; i < len; i++)
		{
			min = i;
			for (j = i + 1; j < len; j++)
			{
				if (k[min] > k[j] && k[j] != -1)
				{
					min = j;
				}
				else if (-1 == k[min] && k[j] != -1)
				{
					min = j;
				}
			}
			if (min != i)
			{
				swap(k[i], k[min]);
				swap(a[i], a[min]);
			}
		}
	}
};

int main()
{
#define N 4
	int len = N;
	int a[] =
	{ 2, 4, 8, 3 }; //a��ʵ�ʼ�����û��ʹ��
	int k[] =
	{ 4, 3, -1, 4 };
	RepeatSet set(a, k, len);
	set.print();
	cout << endl << "result:" << set.getRCombination(12) << endl;
	cout << endl << "result:" << set.getRCombination(4) << endl;
	return 0;
}
