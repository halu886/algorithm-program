/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (!nums.size())
        {
            return nums.size();
        }
        int beginIndex = 0;
        int endIndex = nums.size() - 1;

        while (beginIndex < endIndex)
        {
            if (nums[beginIndex] != val)
            {
                ++beginIndex;
                continue;
            }

            while (nums[endIndex] == val && endIndex > beginIndex)
            {
                --endIndex;
            }

            if (endIndex <= beginIndex)
            {
                break;
            }

            nums[beginIndex++] = nums[endIndex];
            nums[endIndex--] = val;
        }

        while (endIndex > -1 && nums[endIndex] == val)
        {
            --endIndex;
        }
        return endIndex + 1;
    }
};
