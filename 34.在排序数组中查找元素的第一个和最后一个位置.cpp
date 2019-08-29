/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int begin = 0;
        int end = nums.size();
        vector<int> range;
        range.push_back(-1);
        range.push_back(-1);
        while (begin < end)
        {
            int mid = begin + (end - begin) >> 1 + 1;
            if (mid < target)
            {
                begin = mid;
            }
            else if (mid > target)
            {
                end = mid;
            }
            else
            {
                bool isEnd = false;
                bool isBegin = false;
                int isEndIndex = mid;
                int isBeginIndex = mid;
                while (!(isEnd && isBegin))
                {
                    if (!isEnd && nums[isEndIndex] == target)
                    {
                        range[1] = isEndIndex++;
                        if (isEndIndex >= nums.size())
                        {
                            isEnd = true;
                        }
                    }
                    else if (!isEnd && nums[isEndIndex] != target)
                    {
                        isEnd = true;
                    }

                    if (!isBegin && nums[isBeginIndex] == target)
                    {
                        range[0] = isBeginIndex++;
                        if (isBeginIndex >= nums.size())
                        {
                            isBegin = true;
                        }
                    }
                    else if (!isBegin && nums[isBeginIndex] != target)
                    {
                        isEnd = true;
                    }
                }
            }
        }
        return range;
    }
};
