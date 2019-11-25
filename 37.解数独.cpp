/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
class Solution
{
private:
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> boxes;
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
        return false;
    }
    bool has(char c, int i, int j, int b)
    {
        return rows[i][c - '0'] || cols[j][c - '0'] || boxes[b][c - '0'];
    }
    void erase(char c, int i, int j, int b)
    {
        rows[i][c - '0'] = false;
        cols[j][c - '0'] = false;
        boxes[b][c - '0'] = false;
    }

public:
    void
    solveSudoku(vector<vector<char>> &board)
    {
        n = board.size();
        m = sqrt(n);
        rows.assign(n, vector<bool>(n + 1));
        cols.assign(n, vector<bool>(n + 1));
        boxes.assign(n, vector<bool>(n + 1));

        init(board);

        core(board, 0, 0);
    }
};
