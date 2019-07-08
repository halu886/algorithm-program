/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (!nums.size())
        {
            return 0;
        }
        int tempK = 0;
        int tempNextK = 0;

        // cout << nums.size() << endl;
        while (tempNextK < nums.size())
        {
            // cout << tempK << "\t" << tempNextK << (nums[tempK] == nums[tempNextK]) << endl;
            if (nums[tempK] == nums[tempNextK])
            {
                ++tempNextK;
                continue;
            }
            nums[++tempK] = nums[tempNextK++];
        }
        return tempK + 1;
    }
};
