/*
 * @lc app=leetcode.cn id=16 lang=javascript
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (39.72%)
 * Total Accepted:    21.8K
 * Total Submissions: 54.8K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
    nums = nums.sort((x, y) => { return x - y; })
    //待定
    let result = nums[0] + nums[1] + nums[nums.length - 1];
    for (let i = 0; i < nums.length - 2; i++) {
        const numI = nums[i]
        const sum = target - numI;
        let j = i + 1;
        let x = nums.length - 1;
        // console.log(nums);
        while (j < x) {
            const diffSum = sum - nums[j] - nums[x];
            const tempSum = nums[i] + nums[j] + nums[x];
            // console.log(i, j, x, nums[i], nums[j], nums[x], nums[i] + nums[j] + nums[x], result);
            if (Math.abs(diffSum) < Math.abs(target - result)) {
                result = nums[i] + nums[j] + nums[x];
            }
            if (result === target) {
                return target;
            } else if (tempSum > target) {
                while (j < x && nums[x] === nums[x - 1]) { x-- }
                x--;
            } else {
                while (j < x && nums[j] === nums[j + 1]) { j++ }
                j++;
            }
        }
    }
    return result
};

