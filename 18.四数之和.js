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
    nums = nums.sort((x, y) => x > y);
    let i = 0, j = nums.length - 1;
    let guard = false;
    console.log(nums)
    while (j - i >= 2) {
        let x = i + 1, z = j - 1;
        while (x < z) {
            console.log(nums[x], nums[z], nums[i], nums[j])
            const sum = nums[x] + nums[z] + nums[i] + nums[j];
            if (sum === target) {
                arrs.push([nums[x], nums[z], nums[i], nums[j]]);
                break;
            }

            if (sum < target) {
                while (nums[x] === nums[x + 1] && x < z)++x;
                ++x;
            } else if (sum > target) {
                while (nums[z] === nums[z - 1] && x < z)--z;
                --z;
            }
        }
        if (guard) {
            guard = false;
            while (nums[i] === nums[i + 1] && (j - i >= 2))++i;
            ++i;
        } else {
            guard = true;
            while (nums[j] === nums[j - 1] && (j - i >= 2))--j;
            --j;
        }
    }
    console.log(arrs);
    return arrs;
};

