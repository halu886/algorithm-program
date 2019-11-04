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
        if ((!s.size() && !p.size()) || p == "*")
        {
            return true;
        }

        if (!s.size() || !p.size())
        {
            return false;
        }

        if (p[0] == '*' && (isMatch(s.substr(0), p.substr(1)) ||
                            isMatch(s.substr(1), p.substr(0)) ||
                            isMatch(s.substr(1), p.substr(1))))
        {
            return true;
        }

        if ((s[0] == p[0] || p[0] == '?') && isMatch(s.substr(1), p.substr(1)))
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
