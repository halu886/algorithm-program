
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
        for (int i = 0; i < k; i++)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
        }

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *third = NULL;
        // k内所有节点指针往上翻转
        for (int i = 0; i < k - 1; i++)
        {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        head->next = reverseKGroup(second, k);
        return first;
    }
};