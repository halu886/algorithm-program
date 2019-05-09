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
    console.log(nums);
    nums = nums.sort((x, y) => {
        console.log(x, typeof x, y, typeof y, x > y);
        return x > y
    });
    console.log(nums);
    let i = 0, j = nums.length - 1;
    console.log(nums)
    while (i < nums.length - 3) {
        let x = i + 1, z = j - 1;
        while (x < z) {
            console.log(nums[i], nums[x], nums[z], nums[j])
            const sum = nums[i] + nums[x] + nums[z] + nums[j];
            if (sum === target) {
                arrs.push([nums[i], nums[x], nums[z], nums[j]]);
                while (nums[x] === nums[x + 1] && x < z)++x;
                while (nums[z] === nums[z - 1] && x < z)--z;
                --z;
                ++x;
                continue;
            }

            if (sum < target) {
                while (nums[x] === nums[x + 1] && x < z)++x;
                ++x;
            } else if (sum > target) {
                while (nums[z] === nums[z - 1] && x < z)--z;
                --z;
            }
        }
        if (j - i > 2) {
            while (nums[j] === nums[j - 1] && (j - i >= 2))--j;
            --j;
        } else {
            while (nums[i] === nums[i + 1] && (j - i >= 2))++i;
            j = nums.length - 1
            ++i;
        }
    }
    console.log(arrs);
    return arrs;
};

