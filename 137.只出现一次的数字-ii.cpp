/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int one = 0;
        int two = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            one = one ^ nums[i] & ~two;
            two = two ^ nums[i] & ~one;
        }
        return one;
    }
};
// @lc code=end
