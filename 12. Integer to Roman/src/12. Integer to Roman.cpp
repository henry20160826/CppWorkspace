//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
using namespace std;

class Solution
{
public:
	//1-3999
	string intToRoman(int num)
	{
		int i = 0;
		int x = 1;
		int a[4];
		string biao = "IVXLCDM";
		while (i < 4)
		{
			a[i] = num / x % 10;
			x *= 10;
			i++;
		}
		i--;
		string rs = "";
		for (; i >= 0; --i)
		{
			switch (a[i])
			{
			case 0:
				break;
			case 4:
				rs += biao[i * 2];
				rs += biao[i * 2 + 1];
				break;
			case 9:
				rs += biao[i * 2];
				rs += biao[i * 2 + 2];
				break;
			case 3:
				rs += biao[i * 2];
			case 2:
				rs += biao[i * 2];
			case 1:
				rs += biao[i * 2];
				break;
			default:
				rs += biao[i * 2 + 1];
				for (int j = a[i] - 5; j > 0; --j)
				{
					rs += biao[i * 2];
				}
				break;
			}
		}
		return rs;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
