/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution
{

public:
    vector<string> result;
    vector<string> generateParenthesis(int n)
    {
        result = {};
        recursion("", n);

        return result;
    }

    void recursion(string str, int n)
    {
        if (str.size() == n)
        {
            if (isValid(str))
            {
                result.push_back(str);
            }
            else
            {
                return;
            }
        }
        if (isValid(str))
        {
            recursion(str + "(", n);
            recursion(str + ")", n);
        }
    }
    bool isValid(string str)
    {
        int balance = 0;

        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c == '(')
            {
                balance++;
            }
            else if (c == ')')
            {
                balance--;
            }
        }
        // return balance >= 0
        return true;
    }
};