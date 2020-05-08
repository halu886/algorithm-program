/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后K个零
 */

// @lc code=start
class Solution
{
public:
    int preimageSizeFZF(int K)
    {
        int a = 26;
        int ret = 1;
        for (int i = 1; i < a; i++)
        {
            ret *= i;
        }
        cout << ret;
        return 0;
    }
};
// @lc code=end
