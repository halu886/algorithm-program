/*
 * @lc app=leetcode.cn id=6 lang=javascript
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (39.89%)
 * Total Accepted:    20K
 * Total Submissions: 50K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
    if (numRows === 1) return s;
    const doubleArray = []
    for (let i = 0; i < s.length; i++) {
        doubleArray.push([])
    }
    let tempI = 0;// 横轴
    let tempJ = 0;// 纵轴
    let isStraight = true;
    let resultStr = "";
    for (const char of s) {
        doubleArray[tempI][tempJ] = char;
        // console.log(doubleArray, tempI, tempJ)
        if (isStraight) {
            if (tempJ < numRows - 1) {
                ++tempJ;
                continue;
            }
            isStraight = false;
            ++tempI;
            --tempJ;
            continue;
        } else {
            if (!tempJ) {
                isStraight = true;
                ++tempJ;
                continue;
            }
            ++tempI;
            --tempJ;
        }
    }
    // console.log(doubleArray);
    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < s.length; j++) {
            if (doubleArray[j][i]) {
                resultStr += doubleArray[j][i];
            }
        }
    }
    return resultStr;
};
