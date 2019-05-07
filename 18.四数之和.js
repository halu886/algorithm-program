/*
 * @lc app=leetcode.cn id=18 lang=javascript
 *
 * [18] 四数之和
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    const arrs = []
    nums = nums.sort((x, y) => x < y);
    let i = 0, j = nums.length - 1;
    while (j - i < 2) {
        let x = i + 1, z = j - 1;
        while (x < z) {
            const arr = []
            const sum = nums[x] + nums[y] + nums[i] + nums[j];
            if (sum === target) {
                arr.push(nums[x], nums[y], nums[i], nums[j]);
                break;
            }

            if (sum < target) {
                while (nums[x] === nums[x + 1] && x < z)++x;
                ++x
            } else if (sum > target) {
                while (nums[z] === nums[z - 1] && x < z)--z;
                --z;
            }
        }

    }
};

