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
        bool is_equel;
        int dividend_symbol;
        int divisor_symbol;
        cout << dividend << "\t" << divisor << "\t" << dividend_symbol << endl;
        if (dividend < 0)
        {
            dividend_symbol = -1;
        }
        else
        {
            dividend_symbol = 1;
        }

        if (divisor < 0)
        {
            divisor_symbol = -1;
        }
        else
        {
            divisor_symbol = 1;
        }

        if (dividend_symbol == divisor_symbol)
        {
            is_equel = true;
        }
        else
        {
            is_equel = false;
        }

        int count = 0;
        int add_count = 1;
        int divisor_add = divisor;
        int max = 2;
        cout << dividend_symbol << "\t" << divisor_symbol << "\t" << is_equel << endl;
        if (is_equel)
        {
            cout << (dividend - divisor) << endl;
            while (dividend - divisor >= dividend_symbol || dividend == divisor)
            {
                if (dividend == 0)
                {
                    break;
                }
                cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
                if (dividend - divisor_add >= dividend_symbol || dividend == divisor_add)
                {
                    dividend -= divisor_add;
                    count += add_count;
                }
                else
                {
                    divisor_add -= divisor;
                    --add_count;
                }
            }
        }
        else
        {
            cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
            if (dividend > 0)
            {
                while (dividend + divisor >= dividend_symbol || dividend + divisor == 0)
                {
                    cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
                    if (dividend - divisor_add >= dividend_symbol || dividend + divisor_add == 0)
                    {
                        dividend += divisor_add;
                        count -= add_count;
                    }
                    else
                    {
                        divisor_add -= divisor;
                        --add_count;
                    }
                }
                // cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
            }
            else
            {
                cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
                while (dividend + divisor <= dividend_symbol || dividend + divisor == 0)
                {
                    cout << dividend << "\t" << divisor << "\t" << divisor_add << "\t" << dividend_symbol << "\t" << count << endl;
                    if (dividend + divisor_add <= dividend_symbol || dividend + divisor_add == 0)
                    {
                        dividend += divisor_add;
                        count -= add_count;
                    }
                    else
                    {
                        divisor_add -= divisor;
                        --add_count;
                    }
                }
                // cout << dividend << "\t"<<divisor<<"\t"<<divisor_add<<"\t"<<dividend_symbol<<"\t"<<count<<endl;
            }
        }
        return count;
    }
};
