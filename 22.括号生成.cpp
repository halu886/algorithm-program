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
        // cout << "start" << endl;
        recursion("", n);

        // cout << "end" << endl;
        // cout_v();

        return result;
    }

    void cout_v()
    {

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
    }
    void recursion(string str, int n)
    {
        // cout << "start recursion" << endl;
        // cout_v();
        if (str.size() == n * 2)
        {
            if (balance(str) == 0)
            {
                result.push_back(str);
            }
            return;
        }
        // cout << "balance:" << str << "\t" << balance(str) << endl;
        if (balance(str) >= 0)
        {
            recursion(str + "(", n);
            recursion(str + ")", n);
        }
        // cout << "end recursion" << endl;
    }
    int balance(string str)
    {
        int balance = 0;

        for (int i = 0; i <= str.length(); i++)
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
        return balance;
    }
};