/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
int firstMissingPositive(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 1 && nums[i] < nums.size())
        {
            int t = nums[i] - 1;
            if (nums[i] != nums[t])
            {
                swap(nums[i], nums[t]);
                i -= (t > i);
            }
        }
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}
// @lc code=end