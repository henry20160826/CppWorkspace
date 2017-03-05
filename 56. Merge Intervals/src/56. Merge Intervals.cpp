//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval
{
	int start;
	int end;
	Interval() :
			start(0), end(0)
	{
	}
	Interval(int s, int e) :
			start(s), end(e)
	{
	}
};
class Solution
{
public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		int len = intervals.size();
		int i, j;
		for (i = 0; i < len; ++i)
		{
			for (j = i + 1; j < len; ++j)
			{
				if (isMerge(intervals, i, j))
				{
					j = i;
					--len;
				}
			}
		}
		return intervals;
	}
	bool isMerge(vector<Interval>& intervals, int i, int j)
	{
		//可以合并时，删除j,保留i
		if (intervals[j].start <= intervals[i].start
				&& intervals[i].start <= intervals[j].end)
		{
			if (intervals[i].end > intervals[j].end)
			{
				intervals[j].end = intervals[i].end;
			}
			intervals[i] = intervals[j];
			intervals.erase(intervals.begin() + j);
			return true;
		}
		if (intervals[i].start <= intervals[j].start
				&& intervals[j].start <= intervals[i].end)
		{
			if (intervals[j].end > intervals[i].end)
			{
				intervals[i].end = intervals[j].end;
			}
			intervals.erase(intervals.begin() + j);
			return true;
		}
		return false;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
