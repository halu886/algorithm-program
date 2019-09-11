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
            unordered_map<char, int> x;
            unordered_map<char, int> y;
            for (int j = 0; j < 9; j++)
            {
                // cout << i << "\t" << j << "\t" << board[i][j] << "\t" << (x.find(board[i][j]) != x.end()) << endl;
                // cout << i << "\t" << j << "\t" << board[j][i] << "\t" << (y.find(board[j][i]) != y.end()) << endl;
                if (x.find(board[i][j]) != x.end() && board[i][j] != '.')
                {
                    return false;
                }
                if (y.find(board[j][i]) != y.end() && board[j][i] != '.')
                {
                    return false;
                }
                x[board[i][j]] = 1;
                y[board[j][i]] = 1;
            }
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_map<char, int> chunk;
                for (int x = i; x < i + 3; x++)
                {
                    bool isBreak = false;
                    for (int y = j; y < j + 3; y++)
                    {
                        if (chunk.find(board[x][y]) != chunk.end() && board[x][y] != '.')
                        {
                            return false;
                        }
                        chunk[board[x][y]] = 1;
                    }
                }
            }
        }

        return true;
    }
};
