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
                ++maxLength;
            }
            else
            {
                if (!leftSum)
                {
                    string substr = s.substr(1);
                    if (substr.size() < maxLength)
                    {
                        return maxLength;
                    }
                    int anotherLength = longestValidParentheses(s.substr(1));
                    return anotherLength > maxLength ? anotherLength : maxLength;
                }
                --leftSum;
                ++maxLength;
            }
        }

        if (leftSum)
        {
            int rightSub = longestValidParentheses(s.substr(1));
            int leftSub = longestValidParentheses(s.substr(0, s.size() - 1));
            return rightSub > leftSub ? rightSub : leftSub;
        }
        return maxLength;
    }
};
