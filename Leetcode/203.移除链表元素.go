/*
 * @lc app=leetcode.cn id=203 lang=golang
 *
 * [203] 移除链表元素
 */
package leetcode

/* --- 2022-01-17-17-37 --- */

// https://github.com/fengwei2002/Algorithm
// problem link:
// https://leetcode.cn/problems/remove-linked-list-elements/
// solution link: 
// https://leetcode.cn/problems/remove-linked-list-elements/solution/lc203-fengwei2002-by-kycu-komv/

 type ListNode struct {
	 Val int
	 Next *ListNode
 }
// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	for p := dummy; p != nil; p = p.Next { 
		q := p.Next
		for q != nil && q.Val == val {
			q = q.Next
		}
		p.Next = q
	}
	return dummy.Next
}
// @lc code=end

