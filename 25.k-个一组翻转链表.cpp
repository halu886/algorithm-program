
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
        // ListNode *mid = NULL;
        // double midIndex = (double)k / 2.0;
        for (int i = 0; i < k; i++)
        {
            cout << temp->val << endl;
            if (temp == NULL)
            {
                return head;
            }
            // if (i <= midIndex && i + 1 > midIndex)
            // {
            //     mid = temp;
            // }
            temp = temp->next;
        }

        cout << "loop over" << endl;
        ListNode *first = head;
        ListNode *second = head->next;
        // k内所有节点指针往上翻转
        for (int i = 0; i < k - 1; i++)
        {
            cout << "convert" << endl;
            cout << first->val << "\t" << second->val << endl;
            cout << "convert end" << endl;
            ListNode *third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        head->next = reverseKGroup(second->next, k);
        return second;
    }
};