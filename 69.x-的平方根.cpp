/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int middle = x / 2;
        int mSqrt = middle * middle;
        int mPreSqrt = (middle - 1) * (middle - 1);
        int mNextSqrt = (middle + 1) * (middle + 1);
        while (!(mPreSqrt < x && mNextSqrt > x))
        {
            if (mSqrt < x)
            {
                middle = middle + (x - middle) / 2;
            }
            else
            {
                middle /= 2;
            }
            int mSqrt = middle * middle;
            int mPreSqrt = (middle - 1) * (middle - 1);
            int mNextSqrt = (middle + 1) * (middle + 1);
        }
    }
};
// @lc code=end
