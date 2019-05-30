/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution
{

public:
    bool isValid(string str);
    void recursion(vector<string> *pResult, string str, int n);
    vector<string> generateParenthesis(int n);
};

vector<string> Solution::generateParenthesis(int n)
{

    vector<string> resultV();

    recursion(&resultV, "", n);

    return resultV;
}

void Solution::recursion(vector<string> *pResult, string str, int n)
{
    if (str.size() == n)
    {
        if (this.isValid(str))
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

bool Solution::isValid(string str)
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
    // return balance >= 0
    return true;
}