/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return null;
        }
        ListNode *p_index = p_head = &(lists[0]);
        int first_index = 0;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i].val < p_index.val)
            {
                p_index = p_head = vector[i];
                first_index = i;
            }
        }
        vector[first_index] = vector[first_index].next;

        for (; !isOver(lists);)
        {
            ListNode *p_temp = lists[0];
            int num_p = 0;
            for (int j = 0; j < lists.size(); j++)
            {
                if (!lists[j])
                {
                    continue;
                }
                if (lists[j] < p_temp.val)
                {
                    p_temp = lists[j];
                    num_p = j;
                }
            }

            p_index.next = p_temp;
            p_index = p_temp;
            lists[num_p] = lists[num_p].next;
        }

        return p_head;
    }

    bool isOver(vector<ListNode *> &lists)
    {
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                return false;
            }
        }
        return true;
    }
};
