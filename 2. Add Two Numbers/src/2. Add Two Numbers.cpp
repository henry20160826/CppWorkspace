//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p3 = new ListNode(1);
		ListNode *pstart = p3;
		while (p1 != NULL && p2 != NULL)
		{
			p3->next = new ListNode(p1->val + p2->val);
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		while (p1 != NULL)
		{
			p3->next = new ListNode(p1->val);
			p1 = p1->next;
			p3 = p3->next;
		}
		while (p2 != NULL)
		{
			p3->next = new ListNode(p2->val);
			p2 = p2->next;
			p3 = p3->next;
		}
		p3 = pstart;
		int carry = 0;
		while (p3->next != NULL)
		{
			p3->next->val += carry;
			carry = p3->next->val / 10;
			p3->next->val = p3->next->val % 10;
			p3 = p3->next;
		}
		if (carry != 0)
		{
			p3->next = new ListNode(1);
		}
		p3 = pstart->next;
		delete (pstart);
		pstart = p3;
		return pstart;
	}
};
int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
