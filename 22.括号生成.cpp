/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> resultV = new verctor();

        recursion(&resultV, "", n);

        return resultV;
    }

public:
    void recursion(Vector *pResult, String str, int n)
    {
        if (str.size() == n)
        {
            if (isValid(str))
            {
                *pResult.push(str);
            }
            else
            {
                return;
            }
        }

        if (isValid(str))
        {
            recursion(pResult, str + "(", n);
            recursion(pResult, str + ")", n);
        }
    }

public:
    Boolean isValid(string str)
    {
        int balance = 0;

        for (int i = 0; i < str.length, i++)
        {
            char c = str[i];
            if (c == "(")
            {
                balance++;
            }
            else if (c == ")")
            {
                balance--;
            }
        }
        return balance >= 0
    }
};
