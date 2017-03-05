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
		//���ָ��ÿ���ƶ�2��λ�ã�����ָ��ÿ���ƶ�һ��λ��
		//������ڻ���fast pointer��׷slow pointer��ʱ��ÿ�ξ�������1�������Բ�����ȥ
		if (NULL == head)
		{
			return NULL;
		}
		ListNode *slow = head, *fast = head, *entry = head;
		int slowstep = 0;		//slow pointer�ߵľ������
		while (NULL != fast->next && NULL != fast->next->next)
		{
			slow = slow->next;
			++slowstep;
			fast = fast->next->next;
			if (slow == fast)
			{
				while (entry != slow)
				{
					//���������ոպ�
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
