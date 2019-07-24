/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_equel;
        int dividend_symbol;
        int divisor_symbol;
        if(dividend<0){
            dividend_symbol = -1;
        }else{
            dividend_symbol = 1;
        }

        if(divisor<0){
            divisor_symbol = -1;
        }else{
            divisor_symbol = 1;
        }

        if(dividend_symbol==divisor_symbol){
            is_equel = true;
        }else{
            is_equel = false;
        }

        int count = 0;
        int add_count = 1;
        int divisor_add = divisor;
        int max = 2;
        // cout << dividend_symbol << "\t" << divisor_symbol << "\t" << is_equel << endl;
        if(is_equel){
            while(dividend-divisor>=dividend_symbol||dividend==divisor){
                if(dividend-divisor_add>=dividend_symbol||dividend==divisor_add){
                    dividend -= divisor_add;
                    count += add_count;
                }else{
                    divisor_add -= divisor;
                    --add_count;
                }
            }
        }else{
            if(dividend>0){
                while(dividend+divisor>=dividend_symbol||dividend==divisor){
                    if(dividend-divisor_add>=dividend_symbol||dividend==divisor_add){
                        dividend -= divisor_add;
                        count -= add_count;
                    }else{
                        divisor_add -= divisor;
                        --add_count;
                    }
                }
            }else{
                while(dividend+divisor<=dividend_symbol||dividend==divisor){
                    if(dividend+divisor_add<=dividend_symbol||dividend==divisor_add){
                        dividend += divisor_add;
                        count -= add_count;
                    }else{
                        divisor_add -= divisor;
                        --add_count;
                    }
                }
            }
        }
        return count;
    }
};

