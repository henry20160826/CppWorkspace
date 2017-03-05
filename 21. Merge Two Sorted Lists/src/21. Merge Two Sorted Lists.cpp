//============================================================================
// Name        : .cpp
// Author      : dh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL)
		{
			return l2;
		}
		else if (l2 == NULL)
		{
			return l1;
		}
		else
		{
			ListNode* p1 = l1;
			ListNode* p2 = l2;
			ListNode* head, *ph;
			if (p1->val < p2->val)
			{
				ph = p1;
				p1 = p1->next;
			}
			else
			{
				ph = p2;
				p2 = p2->next;
			}
			head = ph;
			while (p1 != NULL && p2 != NULL)
			{
				if (p1->val < p2->val)
				{
					ph->next = p1;
					p1 = p1->next;
				}
				else
				{
					ph->next = p2;
					p2 = p2->next;
				}
				ph = ph->next;
			}
			if (p1 == NULL)
			{
				ph->next = p2;
			}
			else
			{
				ph->next = p1;
			}
			return head;
		}
		return NULL;
	}
};

int main()
{
	cout << "Hello World" << endl; // prints Hello World
	return 0;
}
