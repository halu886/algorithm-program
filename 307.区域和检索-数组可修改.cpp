/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    vector<int> C;
    vector<int> nums;

    NumArray(vector<int> &nums) : nums(nums) {
        for (int i = 0; i <= nums.size(); ++i) {
            C.push_back(0);
        }
        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int i, int val) {
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += val;
        }
    }

    void update(int i, int val) {
        int add = val - nums[i];
        nums[i] = val;
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += add;
        }
    }

    int getSum(int i) {
        int sum = 0;
        for (int k = i; k > 0; k -= lowbit(k)) {
            sum += C[k];
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

