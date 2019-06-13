/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] k个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *mid = NULL;
        double midIndex = double(k) / 2;
        if (int i = 0; i < k; i++)
        {
            if (temp = NULL)
            {
                return head;
            }
            if (i <= midIndex && i + 1 > midIndex)
            {
                mid = temp;
            }
            temp = temp->next;
        }

        // k内所有节点指针往上翻转
        for (int i = 0; i < k / 2; i++)
        {
            if ()
        }
    }
};
