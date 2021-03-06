//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (NULL == head || 0 == k)
		{
			return head;
		}
		//使rear指向最后一个节点，计算链表长度
		ListNode *rear;
		rear = head;
		int len = 1;
		while (rear->next != NULL)
		{
			rear = rear->next;
			++len;
		}
		if (1 == len)
		{
			return head;
		}
		//计算在另一个方向旋转多少
		k = len - k % len;
		if (k == len) //不需要旋转直接返回
		{
			return head;
		}
		//找到旋转位置进行旋转
		ListNode *rear1, *head2;
		int i;
		for (i = 1, rear1 = head; i < k; ++i, rear1 = rear1->next)
		{
		}
		head2 = rear1->next;
		rear->next = head;
		rear1->next = NULL;
		return head2;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
