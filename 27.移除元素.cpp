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
            return 0;
        }
        int beginIndex = 0;
        int endIndex = nums.size() - 1;

        while (beginIndex < endIndex)
        {
            cout << beginIndex << "\t" << endIndex << endl;
            if (nums[beginIndex] != val)
            {
                ++beginIndex;
                continue;
            }

            while (nums[endIndex] == val)
            {
                --endIndex;
            }

            if (endIndex <= beginIndex)
            {
                break;
            }

            nums[beginIndex++] = nums[endIndex];
            nums[endIndex--] = val;
            cout << "last" << endl;
            cout << beginIndex << "\t" << endIndex << endl;
            cout << "last end" << endl;
        }

        return beginIndex + 1;
    }
};
