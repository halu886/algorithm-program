/*
 * @lc app=leetcode.cn id=15 lang=javascript
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.56%)
 * Total Accepted:    46K
 * Total Submissions: 211.8K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    const resultNumArr = [];
    for (let i = 0; i < nums.length; i++) {
        const numI = nums[i];
        for (let j = i + 1; j < nums.length; j++) {
            const numJ = nums[j];
            for (let x = j + 1; x < nums.length; x++) {
                const numX = nums[x];
                if (!(numI + numJ + numX)) {
                    let isExist = false;
                    for (const resultNum of resultNumArr) {
                        if (~resultNum.indexOf(numI) && ~resultNum.indexOf(numJ) && ~resultNum.indexOf(numX)) {
                            isExist = true
                            break;
                        }
                    }
                    if (!isExist) {
                        resultNumArr.push([numI, numJ, numX].sort())
                    }
                }
            }
        }
    }
    return resultNumArr;
};

