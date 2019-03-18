/*
 * @lc app=leetcode.cn id=10 lang=javascript
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (20.82%)
 * Total Accepted:    10.2K
 * Total Submissions: 48.1K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的元素。
 * 
 * 
 * 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
    let index = 0;
    let stars = [];
    let indexS = 0;
    let isStar = false;
    while (indexS >= 0 && indexS < s.length) {
        const charS = s[indexS];
        const regexChar = p[index]
        console.log(index, indexS)
        if (regexChar == "*") {
            const starEnd = stars[stars.length - 1];
            if (!starEnd || (starEnd && starEnd.index != index)) {
                stars.push({ index, passCount: 0, waitPassCount: 0, indexS })
                ++index;
                continue
            }
            if (!starEnd.waitPassCount) {
                --index
                ++indexS;
            } else {
                ++index;
                isStar = false;
            }
            continue
        } else if (p[index + 1] === "*") {
            const starEnd = stars[stars.length];
            if (!starEnd || (starEnd && starEnd.index != index)) {
                stars.push({ index, passCount: 0, waitPassCount: 0, indexS })
                ++index;
                continue
            }
        }
        console.log("pass")
        if (regexChar === ".") {
            ++index
            ++indexS
            continue;
        }
        if (regexChar === charS) {
            ++index;
            ++indexS;
            continue;
        }
        if (isStar) {
            stars.pop()
            if (stars.length) {
                const starEnd = stars[stars.length - 1];
                ++starEnd.passCount;
                starEnd.waitPassCount = starEnd.passCount;
                index = starEnd.index - 1;
                indexS = starEnd.indexS;
                isStar = true;
                continue;
            } else {
                index = -1;
                indexS = -1;
            }
        } else {
            if (stars.length) {
                const starEnd = stars[stars.length - 1];
                ++starEnd.passCount;
                starEnd.waitPassCount = starEnd.passCount;
                index = starEnd.index - 1;
                indexS = starEnd.indexS;
                isStar = true;
                continue;
            } else {
                index = -1;
                indexS = -1;
            }
        }
    }
    if (indexS === s.length) {
        if (index == p.length || (index === p.length - 1 && p[p.length - 1] === "*")) {
            return true
        }
    }
    return false;
};

