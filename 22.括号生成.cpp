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
        string tempLeft = "";
        string tempRight = "";
        for (int i = 0; i < n; i++)
        {
            tempLeft += '(';
            tempRight += ')';
        }
        string temp = tempLeft + tempRight;

        {
                }
        while ()
    }
};
