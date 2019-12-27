/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(!nums.size()){
            return false;
        }
        int maxNextStep = nums[0];
        int index = 0;
        while (index < nums.size()-1)
        {
            if((index+nums[index])>maxNextStep){
                maxNextStep = index + nums[index];
            }

            if(index<maxNextStep){
                ++index;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

