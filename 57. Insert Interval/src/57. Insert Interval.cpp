//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		int len = intervals.size();
		int i;
		bool haveMerge = false;
		int position;
		for (i = 0; i < len; ++i)
		{
			if (intervals[i].start > newInterval.start)
			{
				intervals.insert(intervals.begin() + i, newInterval);
				position = i;
				++len;
				break;
			}
		}
		if (len == i)
		{
			intervals.push_back(newInterval);
			position = len;
			++len;
		}

		for (i = position - 1; i < len; ++i)
		{
			if (i < 0)
			{
				i = 0;
			}
			if (isMerge(intervals, position, i))
			{
				if (position > i)
				{
					--position;
				}
				--len;
				--i;
			}
		}

		return intervals;
	}
	bool isMerge(vector<Interval>& intervals, int i, int j)
	{
		if (i == j)
		{
			return false;
		}
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
