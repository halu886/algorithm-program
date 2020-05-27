/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        int val = root->val;
        TreeNode *left = root->left;

        if (!(left && left->val < val && isValidBST(left)))
        {
            cout << 'left' + left && left->val;
            return false;
        }

        TreeNode *right = root->right;
        if (!(right && right->val > val && isValidBST(right)))
        {
            cout << 'right' + right && right->val;
            return false;
        }
        return true;
    }
};
// @lc code=end
