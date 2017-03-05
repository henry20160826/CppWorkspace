//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//Follow up:
//Can you solve it without using extra space?

//OK
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		//快的指针每次移动2个位置，慢的指针每次移动一个位置
		//如果存在环，fast pointer在追slow pointer的时候，每次距离缩短1步，所以不会错过去
		if (NULL == head)
		{
			return NULL;
		}
		ListNode *slow = head, *fast = head, *entry = head;
		int slowstep = 0;		//slow pointer走的距离就是
		while (NULL != fast->next && NULL != fast->next->next)
		{
			slow = slow->next;
			++slowstep;
			fast = fast->next->next;
			if (slow == fast)
			{
				while (entry != slow)
				{
					//两个步长刚刚好
					slow = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}

		return NULL;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
