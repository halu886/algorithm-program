/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 这题实在写不出了，直接抄了@liushang
        if (dividend == 0)
            return 0;

        //  转换为long long型计算，防止 INT32_MIN / -1 溢出
        long long lldividend = dividend, lldivisor = divisor;
        long long cur_bit = 1, result = 0;

        //  转换为整数计算，最后判断符号
        lldividend = abs(lldividend);
        lldivisor = abs(lldivisor);

        //  先将被除数放大 cur_bit 倍
        //  但是要保证被除数 <= 除数
        while (lldividend >= lldivisor << 1)
        {
            lldivisor <<= 1;
            cur_bit <<= 1;
        }

        //  除数依次减去被除数的 cur_bit 倍
        //  右移 cur_bit 循环执行减法
        //  直到 除数为 0 或者 cur_bit == 0
        while (cur_bit > 0 && lldividend > 0)
        {
            if (lldividend >= lldivisor)
            {
                lldividend -= lldivisor;
                result += cur_bit;
            }
            cur_bit >>= 1;
            lldivisor >>= 1;
        }

        //  判断 result 符号
        result = (dividend > 0 && divisor < 0 ||
                  dividend < 0 && divisor > 0)
                     ? -result
                     : result;

        //  判断是否会溢出，并返回结果
        if (result > INT32_MAX)
            return INT32_MAX;
        return (int)result;
    }
};
