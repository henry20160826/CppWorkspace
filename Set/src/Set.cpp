//============================================================================
// Name        : Set.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
using namespace std;
class Set
{
public:
	Set(int *pw, int lenw)
	{
		p = pw;
		len = lenw;
		unique();
	}
	Set* intersection(Set a)
	{

		return this;
	}
	Set* unions(Set a)
	{
		return this;
	}
private:
	int *p;
	int len;
	bool unique()
	{
		sort(p, p + len);
		for (int i = 0; i < len; i++)
		{
		}
		return false;
	}
};
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
