//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include<vector>

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

    ListNode(int x) : val(x), next(NULL)
    {}
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
        int min = 0;
        ListNode *head, *ph;
        int i;
        for (i = 1; i < len; ++i)
        {
            if (lists[i] != NULL && lists[i]->val < lists[min]->val)
            {
                min = i;
            }
        }
        head = lists[min];
        ph = head;
        lists[min] = lists[min]->next;
        while (len > 0)
        {
            min = 0;
            for (i = 1; i < len; ++i)
            {
                if (lists[i] != NULL)
                {
                    --len;
                    lists.erase(i);
                }
                else if (lists[i]->val < lists[min]->val)
                {

                }
            }
        }

        return NULL;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}