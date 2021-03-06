/*
 * @lc app=leetcode.cn id=17 lang=javascript
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (48.52%)
 * Total Accepted:    21.9K
 * Total Submissions: 45K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    const mapping = {
        "1": [],
        "2": ["a", "b", "c"],
        "3": "def".split(""),
        "4": "ghi".split(""),
        "5": "jkl".split(""),
        "6": "mno".split(""),
        "7": "pqrs".split(""),
        "8": "tuv".split(""),
        "9": "wxyz".split(""),
    }
    const matchArr = [];
    if (!digits) { return matchArr }
    function recursion(str, k) {
        if (str.length === digits.length) {
            matchArr.push(str);
            return;
        }
        for (const char of mapping[digits[k]]) {
            str += char;
            recursion(str, k + 1);
            str = str.slice(0, str.length - 1);
        }
    }
    recursion("", 0);
    return matchArr;
};