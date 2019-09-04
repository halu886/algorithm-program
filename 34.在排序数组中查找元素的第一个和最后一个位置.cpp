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
        int end = nums.size() - 1;
        vector<int> range;
        range.push_back(-1);
        range.push_back(-1);

        if (!nums.size())
        {
            return range;
        }
        while (begin <= end)
        {
            int mid;
            mid = begin + ((end - begin) >> 1);
            // cout << begin << "\t" << ((end - begin) >> 1) << "\t" << end << "\t" << mid << endl;
            if (nums[mid] < target)
            {
                begin = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                bool isEnd = false;
                bool isBegin = false;
                int isEndIndex = mid;
                int isBeginIndex = mid;
                while (!(isEnd && isBegin))
                {
                    // cout << "inclose\t" << isEnd << "\t" << isBegin << "\t" << isEndIndex << "\t" << isBeginIndex << "\t" << endl;
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
                        range[0] = isBeginIndex--;
                        if (isBeginIndex >= nums.size())
                        {
                            isBegin = true;
                        }
                    }
                    else if (!isBegin && nums[isBeginIndex] != target)
                    {
                        isBegin = true;
                    }
                }
                break;
            }
        }
        return range;
    }
};
