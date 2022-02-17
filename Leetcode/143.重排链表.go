/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 */
package leetcode

/* --- 2022-02-16-17-43 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 
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
func reorderList(head *ListNode)  {
	if head == nil || head.Next == nil {
		return
	}
	pre := head
	findMidNode := func (node *ListNode) *ListNode {
		slow := node
		fast := node
		for fast.Next != nil && fast.Next.Next != nil { 
			slow = slow.Next
			fast = fast.Next.Next
		}
		return slow
	}
	mid := findMidNode(head)
	
	suf := mid.Next
	mid.Next = nil

	reverseList := func (node *ListNode) *ListNode {
		a := node
		b := node.Next
		for b != nil {
			c := b.Next
			b.Next = a
			a, b = b, c
		}
		node.Next = nil
		return a
	}
	suf = reverseList(suf)

	mergeList := func (l1, l2 *ListNode) {
		l1Dummy := l1 
		l2Dummy := l2
		for l1 != nil && l2 != nil {
			l1Dummy = l1.Next
			l2Dummy = l2.Next
			l1.Next = l2 // l1 下一位指向 l2 
			l1 = l1Dummy // l1 向后移动
			l2.Next = l1 // l2 下一位指向 l1 
			l2 = l2Dummy // l1 向后移动
		}
		return 
	}

	mergeList(pre, suf)
}
// @lc code=end

