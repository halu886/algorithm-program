/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution
{
public:
    bool valid(int n, vector<int> &cols)
    {
        if (cols.size() <= 1)
            return true;
        int row = cols.size() - 1;
        int col = cols.back();
        for (int r = 0; r < row; ++r)
        {
            int c = cols[r];
            if (c == col || abs(c - col) == abs(r - row))
                return false;
        }
        return true;
    }
    void backtrace(int n, vector<int> &cols, vector<vector<int>> &res)
    {
        if (!valid(n, cols))
            return;
        if (cols.size() == n)
        {
            res.push_back(cols);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            cols.push_back(i);
            backtrace(n, cols, res);
            cols.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> cols;
        vector<vector<int>> all;
        backtrace(n, cols, all);
        vector<vector<string>> res;
        for (auto &v : all)
        {
            vector<string> s;
            for (auto &c : v)
            {
                string t(n, '.');
                t[c] = 'Q';
                s.push_back(t);
            }
            res.push_back(s);
        }
        return res;
    }
};