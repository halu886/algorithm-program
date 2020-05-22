/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            vector<int> out;
            int size = q.size(); //取得每一层的长度
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();
                out.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            res.push_back(out);
            flag++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
