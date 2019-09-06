/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            hashtable<char, int> x;
            hashtable<char, int> y;
            for (int j = 0; j < 9; j++)
            {
                if (x.has(board[i][j]))
                {
                    return false
                }
                if (y.has(board[j][i]))
                {
                    return false
                }
                x.push(board[i][j]),1)
                y.push(board[j][i]),1)
            }
        }

        for (int i = 0; i < 9; i += 3)
        {

            for (int j = 0; j < 9; j += 3)
            {
                for (int x = i; x < i + 3)
                {
                }
            }
        }
    }
};
