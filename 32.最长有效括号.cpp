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
                    // cout << "case1\t" << s << "\t" << i << "\t" << s[i] << "\t" << maxLength << endl;
                    // cout << "str\t" << s << "\t" << s.substr(1) << endl;
                    int anotherLength = longestValidParentheses(s.substr(1));
                    // cout << "case2\t" << (anotherLength > maxLength ? anotherLength : maxLength) << endl;
                    return anotherLength > maxLength ? anotherLength : maxLength;
                }
                --leftSum;
                ++maxLength;
            }
        }

        if (leftSum)
        {
            // cout << "case2\t" << s.substr(1) << endl;
            // cout << "str\t" << s << "\t" << s.substr(1) << endl;
            int rightSub = longestValidParentheses(s.substr(1));
            int leftSub = longestValidParentheses(s.substr(0, s.size() - 1));
            return rightSub > leftSub ? rightSub : leftSub;
        }
        // cout << "case3\t" << maxLength << endl;
        return maxLength;
    }
};
