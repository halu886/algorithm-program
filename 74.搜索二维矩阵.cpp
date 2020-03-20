/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int colStartI = 0;
        int colEndI = matric.size();
        int rowSize = matric[0].size();
        int middle = colStartI + (colEndI - colStartI) / 2;
        vector<int> colEnd = matric[colEnd];
        vector<int> colStart = matric[colStartI];
        if (colEnd[colEnd.size() - 1] < target)
        {
            return false;
        }
        if (colStart[colStart.size() - 1] > target)
        {
            return false;
        }
        while (colStartI <= colEndI)
        {
            if (matric[middle][rowSize])
            {
            }
        }
    }
};
// @lc code=end
