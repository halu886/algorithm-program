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

        while (endIndex > -1 && nums[endIndex] == val)
        {
            --endIndex;
        }

        while (beginIndex < endIndex)
        {
            // cout << beginIndex << "\t" << endIndex << endl;
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
            // cout << "last" << endl;
            // cout << beginIndex << "\t" << endIndex << endl;
            // cout << "last end" << endl;
        }

        return endIndex ? beginIndex + 1 : 0;
    }
};
