/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        
        for (int i=0; i<(n+1)/2; i++)    // 行的遍历范围
        {
            for (int j=0; j<n/2; j++)     // 列的遍历范围
            {
             // 由于是旋转赋值，所以temp记录的是最后一个位置上的元素
             //然后逆时针进行覆盖，见上面的图。
                int temp = matrix[n-1-j][i];    
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
// @lc code=end