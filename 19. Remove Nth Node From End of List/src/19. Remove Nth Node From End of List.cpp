//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note:
//Given n will always be valid.
//Try to do this in one pass.

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
	int getLength(ListNode *head)
	{
		int i = 0;
		while (head != NULL)
		{
			++i;
			head = head->next;
		}
		return i;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		n = getLength(head) - n;
		ListNode *p1;
		if (n == 0)
		{
			p1 = head->next;
			delete (head);
			return p1;
		}
		int i = 1;
		ListNode *p = head;
		while (i < n)
		{
			++i;
			p = p->next;
		}
		cout << p->val << endl;
		p1 = p->next;
		p->next = p1->next;
		delete (p1);
		return head;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
