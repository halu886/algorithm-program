/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    void backtrack(vector<int> &nums, int i, vector<vector<int>> &res)
    {
        if (i == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] = nums[j + 1])
            {
                continue;
            }
            swap(nums[i], nums[j]);
            backtrack(nums, j, res);
            swap(nums[i], nums[j]);
        }
    }
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    };
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, res);
        return res;
    }
};
// @lc code=end
