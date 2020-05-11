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
        queue<TreeNode> queue;
        queue.push(root);
        while (qeuue.has())
        {
            array<int> array;
            queue<TreeNode> nextQueue;
            for (tree of queue.pop())
            {
                array.push(tree->left.val, tree->right.val);
                nextQueue.push(tree->left, tree->right);
            }

            int size = array.size();
            for (int i = 0; i < size / 2, i++)
            {
                if (array[i] != array[size - 1 - i])
                {
                    return false;
                }
            }
            queue = nextQueue;
        }
        return true;
    }
};
// @lc code=end
