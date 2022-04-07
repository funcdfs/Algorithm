/*
 * @lc app=leetcode.cn id=24 lang=golang
 *
 * [24] 两两交换链表中的节点
 */
package leetcode
/* --- 2022-04-07-12-53 --- */
// https://github.com/fengwei2002/Algorithm

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
func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{
		Val: -1,
		Next: head,
	}
	cur := dummy
	for cur != nil && cur.Next != nil && cur.Next.Next != nil {
		a := cur
		b := cur.Next
		c := cur.Next.Next
		a.Next = c
		b.Next = c.Next		
		c.Next = b
		cur = b
	}

	return dummy.Next
}
// @lc code=end

