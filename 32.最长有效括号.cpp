/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int leftSum = 0;
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                ++leftSum;
            }
            else
            {
                if (!leftSum)
                {
                    int anotherLength = longestValidParentheses(s.substr(1));
                    return anotherLength > i + 1 ? anotherLength : i + 1;
                }
                --leftSum;
            }
        }

        if (leftSum)
        {
            return longestValidParentheses(s.substr(1));
        }
        return s.size();
    }
};
