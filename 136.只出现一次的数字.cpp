/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a;
        for (int i = 0; i < nums.size(); i++)
        {
            a ^= nums[i];
        }
        return a;
    }
};
// @lc code=end
