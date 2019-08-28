/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
// class Solution
// {
// public:
//     int longestValidParentheses(string s)
//     {
//         int leftSum = 0;
//         int maxLength = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             char ch = s[i];
//             if (ch == '(')
//             {
//                 ++leftSum;
//                 ++maxLength;
//             }
//             else
//             {
//                 if (!leftSum)
//                 {
//                     string substr = s.substr(1);
//                     if (substr.size() < maxLength)
//                     {
//                         return maxLength;
//                     }
//                     int anotherLength = longestValidParentheses(s.substr(1));
//                     return anotherLength > maxLength ? anotherLength : maxLength;
//                 }
//                 --leftSum;
//                 ++maxLength;
//             }
//         }

//         if (leftSum)
//         {
//             int rightSub = longestValidParentheses(s.substr(1));
//             int leftSub = longestValidParentheses(s.substr(0, s.size() - 1));
//             return rightSub > leftSub ? rightSub : leftSub;
//         }
//         return maxLength;
//     }
// };

// class Solution
// {
// public:
//     int longestValidParentheses(string s)
//     {
//         int maxLength = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             for (int j = i + 2; j <= s.size(); j = j + 2)
//             {
//                 int length = j - i;
//                 if (isValid(s.substr(i, length)) && maxLength < length)
//                 {
//                     maxLength = length;
//                 }
//             }
//         }
//         return maxLength;
//     };
//     bool isValid(string substr)
//     {
//         stack<char> strStack;
//         for (int i = 0; i < substr.size(); i++)
//         {
//             if (substr[i] == '(')
//             {
//                 strStack.push('(');
//             }
//             else if (substr[i] == ')' && strStack.size() > 0)
//             {
//                 strStack.pop();
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         if (strStack.size())
//         {
//             return false;
//         }
//         return true;
//     };
// };
#include <array>
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
        {
            return 0;
        }
        int maxLength = 0;
        vector<int> arrayInt;

        for (int i = 0; i < s.size(); i++)
        {
            arrayInt.push_back(0);
        }

        if (s.size() >= 2)
        {
            if (s[0] == '(' && s[1] == ')')
            {
                arrayInt[1] = 2;
                maxLength = 2;
            }
        }

        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                arrayInt[i] = 0;
                continue;
            }

            // for (int j = 0; j < arrayInt.size(); j++)
            // {
            //     cout << arrayInt[j] << endl;
            // }
            // cout << "index\t" << i << endl;
            if (s[i - 1] == '(')
            {
                arrayInt[i] = arrayInt[i - 2] + 2;
            }
            else if (s[i - 1] == ')')
            {
                if (i - arrayInt[i - 1] - 1 < 0)
                {
                    arrayInt[i] = 0;
                    continue;
                }
                // cout << arrayInt[i - 1] << s[i - arrayInt[i - 1] - 1] << "\tarray[i]" << endl;
                if (s[i - arrayInt[i - 1] - 1] == '(')
                {
                    int t = 0;
                    if (i - arrayInt[i - 1] - 2 >= 0)
                    {
                        t = arrayInt[i - arrayInt[i - 1] - 2];
                    }
                    arrayInt[i] = arrayInt[i - 1] + 2 + t;
                }
            }

            if (maxLength < arrayInt[i])
            {
                maxLength = arrayInt[i];
            }
        }
        return maxLength;
    };
};