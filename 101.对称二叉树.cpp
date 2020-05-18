/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; ++i)
            {
                root = q.front();
                q.pop();
                v[i] = root ? root->val : INT_MIN;
                if (root)
                {
                    q.push(root->left);
                    q.push(root->right);
                }
            }
            // 判断是否回文
            for (int i = 0; i < size / 2; ++i)
            {
                if (v[i] != v[size - 1 - i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
