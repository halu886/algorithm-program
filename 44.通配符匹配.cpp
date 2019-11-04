/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j = 0;
        for (int star = 0, i = 0, last = 0; i < s.length();)
        {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?'))
            {
                ++i;
                ++j;
            }
            else if (j < p.size() && p[j] == '*')
            {
                last = i;
                star = ++j;
            }
            else if (star != 0)
            {
                i = ++last;
                j = star;
            }
            else
                return 0;
        }
        for (; j < p.size() && p[j] == '*'; ++j)
            ;
        return j == p.size();
    }
};
// @lc code=end
