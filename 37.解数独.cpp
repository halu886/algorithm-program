/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        unordered_map[9] xs;
        unordered_map[9] ys;
        unordered_map[9] blocks;
        bool isOver = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                xs[i][board[i][j]] = 1;
                ys[j][board[i][j]] = 1;
                blocks[i / 3 * 3 + j / 3][board[i][j]] = 1;
            }
        }

        int i = 0;
        int j = 0;
        while
        {
            if (board[i][j] != '.')
            {
                continue;
            }

            for (int x = 0; x < 9; x++)
            {
                if (!xs[i][x] & !ys[j][x] & !blocks[i / 3 * 3 + j / 3][x])
                {
                    board[i][j] = x;
                }
            }

            if (board[i][j] == '.')
            {
                if (j > 0)
                {
                    j--;
                }
                else
                {
                    x--;
                    j = 9;
                }
            }
        }
        do
            j = 9;
        (isOver)
    }
};
