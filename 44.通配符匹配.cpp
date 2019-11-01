/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution
{
public:
    bool
    isMatch(string s, string p)
    {
        if (!s.size() && !p.size())
        {
            return true;
        }
        if (!s.size() || !p.size())
        {
            return false;
        }
        if (p[0] == '*')
        {
            for (int i = 0; i < s.size(), i++)
            {
                if (isMatch(s.slice(i), p.slice(1)))
                {
                    return true;
                }
            }
        }
        else
        {
            if ((s[0] == p[0] || p[0] == '?') && isMatch(s.slice(1), p.slice(1)))
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
