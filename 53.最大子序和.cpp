/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1;i<nums.size();i++)
        {
            if(nums[i-1]>0){
                nums[i] += nums[i - 1];
            }
            max = max > nums[i] ? max : nums[i];
        }
        return max;
    }
};
// @lc code=end

