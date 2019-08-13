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
                for (int j = i; j < nums.size() && !isArrange; j++)
                {
                    //todo
                    if (nums[i - 1] > nums[j])
                    {
                        isArrange = true;
                        temp = nums[i - 1];
                        nums[i - 1] = nums[j];
                        nums[j] = temp;
                    }
                }
                if (!isArrange)
                {
                    isArrange = true;
                    temp = nums[i - 1];
                    nums[i - 1] = nums[nums.size() - 1];
                    nums[nums.size() - 1] = temp;
                }
                cout << isArrange << "\t" << i << nums[i] << "\t" << nums[i + 1] << endl;
                for (int j = i; j < nums.size(); j++)
                {
                    for (int x = j + 1; x < nums.size(); x++)
                    {
                        // cout << j << "\t" << x << "\t" << nums[j] << "\t" << nums[x] << endl;
                        if (nums[j] > nums[x])
                        {
                            temp = nums[j];
                            nums[j] = nums[x];
                            nums[x] = temp;
                        }
                    }
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
