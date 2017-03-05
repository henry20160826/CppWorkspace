//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode *rear = head, *headprior, *newhead;
		rear = getNextK(head, k);
		if (rear != NULL) //长度足够反转
		{
			reverseList(NULL, head, rear);
			newhead = rear;
			rear = head;
		}
		else //长度不够反转
		{
			return head;
		}

		while (NULL != rear->next)
		{
			headprior = rear;
			head = headprior->next;
			rear = getNextK(head, k);
			if (rear != NULL)
			{
				rear = reverseList(headprior, head, rear);
			}
			else
			{
				break;
			}
		}
		return newhead;
	}
	ListNode* getNextK(ListNode* head, int k)
	{
		ListNode* p = head;
		int i = 1;
		while (p != NULL && i < k)
		{
			p = p->next;
			++i;
		}
		return p;
	}
	ListNode* reverseList(ListNode* headprior, ListNode* head, ListNode *rear)
	{
		//[head,rear]
		//返回逆转之后的尾指针
		if (NULL == head || head == rear)		//没有节点或者0个节点不需要逆转
		{
			return head;
		}
		//现在至少有两个节点，pprior，p不是空指针，pnext有可能是空指针
		ListNode* pprior = head;
		ListNode* p = pprior->next;
		ListNode* pnext = p->next;
		head->next = rear->next;
		while (p != rear)
		{
			p->next = pprior;
			pprior = p;
			p = pnext;
			pnext = p->next;
		}
		p->next = pprior;
//		print(head);
		if (NULL != headprior)
		{
			headprior->next = rear;
		}
		return head;
	}
	void print(ListNode* head)
	{
		ListNode* p = head;
		while (p != NULL)
		{
			cout << p->val << endl;
			p = p->next;
		}
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
