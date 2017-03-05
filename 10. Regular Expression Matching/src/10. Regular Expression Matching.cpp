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
//isMatch("aa","a") ¡ú false
//isMatch("aa","aa") ¡ú true
//isMatch("aaa","aa") ¡ú false
//isMatch("aa", "a*") ¡ú true
//isMatch("aa", ".*") ¡ú true
//isMatch("ab", ".*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú true

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
