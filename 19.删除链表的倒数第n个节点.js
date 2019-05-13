/*
 * @lc app=leetcode.cn id=19 lang=javascript
 *
 * [19] 删除链表的倒数第N个节点
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    let pHead = head;
    let pResult = null;
    let pIndex = head;
    if (!head.next && n == 1) { return null; }
    for (let i = 0; i < n - 1; i++) {
        pIndex = pIndex.next;
    }

    while (pIndex.next) {
        if (pResult) {
            pResult = pResult.next;
        } else {
            pResult = head
        }
        pIndex = pIndex.next;
    }

    if (pResult) {
        pResult.next = pResult.next.next;
    } else {
        pHead.next = pHead.next.next;
    }

    return pHead;
};

