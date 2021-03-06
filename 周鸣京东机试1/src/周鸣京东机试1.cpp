//============================================================================
// Name        : 周鸣京东机试1.cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	//输入山的数量
	int mountains;
	cin >> mountains;
	//输入山的高度
	int *heights = new int[mountains];
	for (int i = 0; i < mountains; i++)
	{
		cin >> heights[i];
	}
	//对数至少与山的数量相同，因为相邻的山总是能相互看到的
	int couples = mountains;

	//相邻的情况在上面已经计算过，现在计算间隔山数量大于1的情况
	int i, j, n, mid;
	//每座山只想编号更大的方向寻找对
	for (i = 0; i < mountains; i++)
	{
		//i与j表示两头的山
		//是否停止从i山开始的搜索，出现一个更高的山之后就没有再搜索的必要了

		//循环在i+mountains-1处停止，因为i+mountains与i相邻，已经在couples中计算过了
		for (j = i + 2; j < i + mountains - 1; j++)
		{
			n = j % mountains;
			mid = (j - 1 + mountains) % mountains;
			if (heights[mid] < heights[i] && heights[mid] < heights[n])
			{
				couples++;
			}
			else
			{
				//mid是相对于i更高的山，停止关于当前i山的搜索，开始下一座山
				break;
			}
		}
	}
	cout << couples;
	return 0;
}
