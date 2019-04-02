/*
 * @lc app=leetcode.cn id=14 lang=javascript
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.46%)
 * Total Accepted:    65.4K
 * Total Submissions: 200.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
var equalSubStr = function (str, oStr) {
    let index = 0;
    while (index < str.length || index < oStr.length) {
        if (str[index] !== oStr[index]) {
            break;
        }
        ++index;
    }
    return str.substring(0, index);
}
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    let repeatStr = strs[0] || ""
    for (let i = 0; i < strs.length; i++) {
        repeatStr = equalSubStr(repeatStr, strs[i])
    }
    return repeatStr
};

