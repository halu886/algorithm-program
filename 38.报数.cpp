/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        --n;
        int res = 1;
        while (n)
        {
            int tempRes = 0;
            int numCount = 0;
            int oldNum = 0;
            while (res)
            {
                int num = res % 10;
                res /= 10;
                if (num == oldNum)
                {
                    ++numCount;
                    continue;
                }
                else
                {
                    tempRes += numCount * pow(10, (numCount + 1)) + oldNum * pow(10, numCount);
                    oldNum = num;
                    numCount = 1;
                }
            }
            res = tempRes;
            --n;
        }
        return to_string(res);
    }
};
// @lc code=end
