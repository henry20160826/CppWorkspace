//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
	ListNode* swapPairs(ListNode* head)
	{
		ListNode* p = head;
		if (NULL == p || NULL == p->next)
		{
			return head;
		}
		//交换前两个节点
		ListNode* pnext = p->next;
		p->next = pnext->next;
		pnext->next = p;
		head = pnext;
		ListNode* pprior = p;
		//赋值语句的返回值，赋值成功返回1，赋值失败返回0
		while (0 < (p = pprior->next) && 0 < (pnext = p->next))
		{
			pprior->next = pnext;
			p->next = pnext->next;
			pnext->next = p;
			pprior = p;
		}
		return head;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
