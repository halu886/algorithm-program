/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */

// @lc code=start
class Solution
{
private:
    int count;

    // todo
    int count(n)
    {
        if (!count)
        {
            return n
        }
        --count;
        int res = 0;
        int oldNum = n % 10;
        n = n / 10;
        int numCount = 0;
        int sumCount = 0;
        while (n)
        {
            int num = n % 10;
            if (num == oldNum)
            {
                ++numCount;
                continue;
            }
            else
            {
                res = numCount * (sumCount + 1) +
            }
        }
    }

public:
    string countAndSay(int n)
    {
        this.count = n;

        return count(1);
    }
};
// @lc code=end
