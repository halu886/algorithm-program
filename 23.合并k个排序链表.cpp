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
// #include <queue>
// using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct cmp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{

public:
    ListNode *
    mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return {};
        }
        ListNode *p_index;
        ListNode *p_head;
        p_index = p_head = NULL;
        int first_index = 0;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty())
        {
            ListNode *p_temp = pq.top();
            pq.pop();
            if (p_head)
            {
                p_index->next = p_temp;
                p_index = p_temp;
            }
            else
            {
                p_index = p_head = p_temp;
            }
            if (p_temp->next)
            {
                pq.push(p_temp->next);
            }
        }

        if (!p_head)
        {
            return {};
        }
        return p_head;
    }
};
