/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
private:
    vector<int> &nums;
    vector<vector<int>> res;
    vector<int> arr;

public:
    void permuteArr()
    {
        if (arr.size() == nums.size())
        {
            arr.push_back(arr);
            return
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!arr.has(nums[i]))
            {
                arr.push_back(nums[i]);
            }
            permuteArr();
            arr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        this->nums = nums;
        permuteArr();
        return this->res;
    }
};
// @lc code=end
