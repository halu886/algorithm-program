/*
 * @lc app=leetcode.cn id=20 lang=javascript
 *
 * [20] 有效的括号
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const mapEnum = {
        "}": "{",
        ")": "(",
        "]": "["
    }
    const stackStr = []

    for (const char of s) {
        if (!mapEnum[char]) {
            stackStr.push(char);
        } else {
            const left = stackStr[stackStr.length - 1];
            if (left === mapEnum[char]) {
                stackStr.pop();
            } else {
                return false
            }
        }
    }

    if (!stackStr.length) {
        return true
    }

    return false
};

