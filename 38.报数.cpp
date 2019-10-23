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
        if (n == 1)
            return "1";
        string strlast = countAndSay(n - 1);
        int count = 1; //计数
        string res;    //存放结果
        for (int i = 0; i < strlast.size(); i++)
        {
            if (strlast[i] == strlast[i + 1]) //计算有多少个相同数字
            {
                count++;
                continue;
            }
            else
            {
                if (strlast[i] != strlast[i + 1])
                {
                    res += to_string(count) + strlast[i];
                    count = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
