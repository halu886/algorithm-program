/*
 * @lc app=leetcode.cn id=21 lang=javascript
 *
 * [21] 合并两个有序链表
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
    console.log(l1, l2);
    let pHead = null;
    let pHead1 = l1;
    let pHead2 = l2;
    let p1 = l1;
    let p2 = l2;
    let p = null;

    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }

    if (l1.val < l2.val) {
        pHead = p1;
        p = p1.next;
        p1 = p1.next;
    } else {
        pHead = p2;
        p = p2.next;
        p2 = p2.next;
    }

    console.log(p1.val, pHead1.val, p2.val, pHead2.val, p1 === pHead1, p2 === pHead2);
    console.log("start");
    while (p1 === pHead1 || p2 === pHead2) {
        console.log(p1.val, pHead1.val, p2.val, pHead2.val, p1 === pHead1, p2 === pHead2);
        if (p1.val < p2.val) {
            p.next = p1;
            p = p.next;
            p1 = p1.next;
        } else {
            p.next = p2;
            p = p.next;
            p2 = p2.next;
        }
    }
    console.log("end");
    console.log(p1.val, pHead1.val, p2.val, pHead2.val, p1 === pHead1, p2 === pHead2);
    console.log("start");
    while (p1 !== null && p1 !== pHead1 && p1 !== null && p2 !== pHead2) {
        console.log(p1.val, pHead1.val, p2.val, pHead2.val, p1 === pHead1, p2 === pHead2);
        if (p1.val < p2.val) {
            p.next = p1;
            p = p.next;
            p1 = p1.next;
        } else {
            p.next = p2;
            p = p.next;
            console.log(p2)
            p2 = p2.next;
        }
    }

    if (p1) {
        // while (p1.next !== pHead1) {
        //     p1 = p1.next;
        // }
        // p1.next = pHead
        p.next = p1;
    } else if (p2) {
        // while (p2.next !== pHead2) {
        //     p2 = p2.next;
        // }
        p.next = p2;
    }

    return pHead;
};

