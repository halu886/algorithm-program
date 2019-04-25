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
    let pY = 0;
    const pointDigit = (new Array(digits.length)).fill(0);
    while (pointDigit[0] === 4 && pointDigit[pointDigit.length - 1] === 4) {
        let match = "";
        for (let j = 0; j < digits.length; j++) {
            const digit = digits[j];
            if (mapping[digit][pointDigit[j]]) {
                match += mapping[digit][pointDigit[j]];
            }
        }
        if (match) {
            matchArr.push(match);
        }
        if (pY < digits.length && pointDigit[pY] < 4) {
            pointDigit[pY] = pointDigit[pY] + 1;
        } else if (py < digits.length - 1 && pointDigit[py] == 4) {
            py++;
        }
    }
    return matchArr;
};

