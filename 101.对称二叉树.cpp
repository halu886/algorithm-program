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
        Queue queue;
        queue.push(Array(root));
        while (true)
        {
            Array array;
            for (tree of queue.pop())
            {
                array.push(tree->left, tree->right);
            }

            for (tree of array)
            {
                if (t)
                {
                }
            }
        }
    }
};
// @lc code=end
