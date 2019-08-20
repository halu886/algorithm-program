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
        // cout << s << endl;
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
                    cout << "case1\t" << s << "\t" << i << "\t" << s[i] << "\t" << maxLength << endl;
                    int anotherLength = longestValidParentheses(s.substr(1));
                    return anotherLength > maxLength ? anotherLength : maxLength;
                }
                --leftSum;
                ++maxLength;
            }
        }

        if (leftSum)
        {
            // cout << "case2\t" << s.substr(1) << endl;
            return longestValidParentheses(s.substr(1));
        }
        // cout << "case3\t" << s.size() << endl;
        return maxLength;
    }
};
