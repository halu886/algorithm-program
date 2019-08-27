/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int reversal = 0;
        int begin = 0;
        int end = nums[nums.size() - 1];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                if (nums[i] < target || nums[i + 1] > target)
                {
                    return -1;
                }
                else if (nums[nums.size() - 1] > target)
                {
                    begin = i + 1;
                }
                else
                {
                    end = i;
                }
                reversal = i + 1;
                break;
            }
        }

        cout << end << "\t" << begin << endl;

        while (end >= begin)
        {
            int mid = (end + begin) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else if (nums[mid] < target)
            {
                begin = mid;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    };
};