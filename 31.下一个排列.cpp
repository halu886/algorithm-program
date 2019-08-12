/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int temp = 0;
        bool isArrange = false;
        for (int i = nums.size() - 1; i > 0 && !isArrange; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                for (int j = i + 1; i < nums.size() && !isArrange; i++)
                {
                    cout << i << "\t" << nums[i] << "\t" << j << "\t" << nums[j] << endl;
                    if (nums[i - 1] > nums[j])
                    {
                        isArrange = true;
                        temp = nums[i - 1];
                        nums[i - 1] = nums[j - 1];
                        nums[j - 1] = temp;
                    }
                }
                cout << "arrange"
                     << "\t" << isArrange << "\t" << i << "\t" << nums[i] << "\t" << endl;
                if (!isArrange)
                {
                    isArrange = true;
                    temp = nums[i - 1];
                    nums[i - 1] = nums[nums.size() - 1];
                    nums[nums.size() - 1] = temp;
                }
            }
        }

        if (!isArrange)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i; j < nums.size(); j++)
                {
                    if (nums[i] > nums[j])
                    {
                        temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
        }
    }
};
