/*
 * @lc app=leetcode.cn id=2 lang=javascript
 *
 * [2] 两数相加
 */

// from fengwei2002/algorithm
// 2021-10-03-15-49
// https://leetcode-cn.com/problems/add-two-numbers/solution/lc2-fengwei2002-mo-ni-gao-jing-du-jia-fa-ng51/

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let head = null;
    let tail = head;

    let t = 0;
    while (l1 || l2 || t > 0) {
        if (l1) {
            t += l1.val;
            l1 = l1.next;
        }
        if (l2) {
            t += l2.val;
            l2 = l2.next;
        }

        if (head == null) {
            head = tail = new ListNode(t % 10);
        } else {
            tail.next = new ListNode(t % 10);
            tail = tail.next;
        }

        t = Math.floor(t / 10);
        // 我吐了，JavaScript 中的除法是精确计算
        // 要使用 C++ 的除法，要写 Math.floor
    }

    return head;
};
// @lc code=end
