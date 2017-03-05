//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include <vector>
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
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		int len = lists.size();
		if (0 == len)
		{
			return NULL;
		}
		ListNode *head, *ph;
		int min = 0;
		int i;
		for (i = 0; i < len && len > 0; ++i)
		{
			if (NULL == lists[i])
			{
				lists.erase(lists.begin() + i);
				--len;
				--i;
			}
			else if (lists[i]->val < lists[min]->val)
			{
				min = i;
			}
		}
		if (len <= 0)
		{
			return NULL;
		}
		head = lists[min];
		ph = head;
		if (lists[min]->next != NULL)
		{
			lists[min] = lists[min]->next;
		}
		else
		{
			--len;
			lists.erase(lists.begin() + min);
		}
		while (len > 0)
		{
			min = 0;
			for (i = 1; i < len; ++i)
			{
				if (lists[i]->val < lists[min]->val)
				{
					min = i;
				}
			}
			ph->next = lists[min];
			ph = ph->next;
			if (lists[min]->next != NULL)
			{
				lists[min] = lists[min]->next;
			}
			else
			{
				--len;
				lists.erase(lists.begin() + min);
			}
		}

		return head;
	}
};

int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
