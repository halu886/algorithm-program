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
    int n = 0;
    int m = 0;

    void init(vector<vector<char>> &board)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int box_id = (i / m) * m + j / m;
                    insert(c, i, j, box_id);
                }
            }
        }
    }
    void insert(char c, int i, int j, int b)
    {
        rows[i][c - '0'] = true;
        cols[j][c - '0'] = true;
        boxes[b][c - '0'] = true;
    }
    bool core(vector<vector<char>> &board, int i, int j)
    {
        if (i == n)
        {
            return true;
        }

        if (j == n)
        {
            return core(board, i + 1, 0);
        }

        if (board[i][j] != '.')
        {
            return core(board, i, j + 1);
        }

        int box_id = (i / m) * m + j / m;

        // todo
        for (int k = 1; k <= n; ++k)
        {
            char c = '0' + k;
            if (has(c, i, j, box_id))
            {
                continue;
            }
            board[i][j] = c;
            insert(c, i, j, box_id);
            if (core(board, i, j + 1))
            {
                return true;
            }
            erase(c, i, j, box_id);
            board[i][j] = '.';
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        n = board.size();
        m = sqrt(n);
        rows.assign(n, vector<bool>(n + 1));
        cols.assign(n, vector<bool>(n + 1));
        boxes.assign(n, vector<bool>(n + 1));

        init(board);

        core(board, 0, 0);
    }
    // void solveSudoku(vector<vector<char>> &board)
    // {
    //     vector<vector<int>> coords;
    //     bool isOver = false;

    //     for (int i = 0; i < 9; i++)
    //     {
    //         for (int j = 0; j < 9; j++)
    //         {
    //             if (board[i][j] == '.')
    //             {
    //                 coords.push_back({i, j});
    //                 continue;
    //             }
    //             // 二维vector未初始化
    //             xs[i][board[i][j]] = 1;
    //             ys[j][board[i][j]] = 1;
    //             blocks[i / 3 * 3 + j / 3][board[i][j]] = 1;
    //         }
    //     }
    //     printVector(xs);
    //     printVector(ys);
    //     printVector(blocks);
    //     printVector(coords);
    //     int index = 0;
    //     while (index < coords.size())
    //     {
    //         int i = coords[index][0];
    //         int j = coords[index][1];
    //         if (board[i][j] != '.')
    //         {
    //             board[i][j] = ++board[i][j];
    //         }
    //         else
    //         {
    //             board[i][j] = 1;
    //         }

    //         int x = board[i][j];

    //         if (!xs[i][x] & !ys[j][x] & !blocks[i / 3 * 3 + j / 3][x])
    //         {
    //             board[i][j] = x;
    //         }

    //         if (board[i][j] == '.')
    //         {
    //             if (j > 0)
    //             {
    //                 j--;
    //             }
    //             else
    //             {
    //                 x--;
    //                 j = 9;
    //             }
    //         }
    //     }
    // }
};
