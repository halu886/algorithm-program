/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
class Solution
{
private:
    vector<vector<bool>> xs;
    vector<vector<bool>> ys;
    vector<vector<bool>> blocks;

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> coords;
        bool isOver = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    coords.push_back({i, j});
                    continue;
                }
                // 二维vector未初始化
                xs[i][board[i][j]] = 1;
                ys[j][board[i][j]] = 1;
                blocks[i / 3 * 3 + j / 3][board[i][j]] = 1;
            }
        }
        printVector(xs);
        printVector(ys);
        printVector(blocks);
        printVector(coords);
        int index = 0;
        while (index < coords.size())
        {
            int i = coords[index][0];
            int j = coords[index][1];
            if (board[i][j] != '.')
            {
                board[i][j] = ++board[i][j];
            }
            else
            {
                board[i][j] = 1;
            }

            int x = board[i][j];

            if (!xs[i][x] & !ys[j][x] & !blocks[i / 3 * 3 + j / 3][x])
            {
                board[i][j] = x;
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
    }
};
