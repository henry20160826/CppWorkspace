//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") �� false
//isMatch("aa","aa") �� true
//isMatch("aaa","aa") �� false
//isMatch("aa", "a*") �� true
//isMatch("aa", ".*") �� true
//isMatch("ab", ".*") �� true
//isMatch("aab", "c*a*b") �� true

#include <iostream>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int lenS = s.length(), lenP = p.length();
		int i = 0, j = 0;
		string subP=p.
		while (i < lenS && j < lenP)
		{
			if(p[j]!=)
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
