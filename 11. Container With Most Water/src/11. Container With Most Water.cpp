//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int len = height.size();
		int max = 0;
		int now;
		int shortLine;
		int maxj;
		for (int i = 0; i < len - 1; ++i)
		{
			maxj = len - 1;
			for (int j = len - 2; j > i; --j)
			{
				if (height[i] < height[j])
				{
					shortLine = height[i];
				}
				else
				{
					shortLine = height[j];
				}
				now = shortLine * (j - i);
				if (now > max)
				{
					max = now;
				}
			}
		}
		return max;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
