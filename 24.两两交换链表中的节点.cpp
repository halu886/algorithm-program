/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }

        ListNode *second;
        ListNode *third;
        if (head->next)
        {
            second = head->next;
            if (second->next)
            {
                third = second->next;
            }
            else
            {
                third = NULL;
            }
            second->next = head;
            head->next = third;
            swapPairsByAhead(head);
            return second;
        }

        return head;
    }
};
