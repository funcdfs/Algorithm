/*
 * @lc app=leetcode.cn id=445 lang=golang
 *
 * [445] 两数相加 II
 */
package leetcode

/* --- 2022-03-01-11-07 --- */

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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	stack1 := make([]int, 0) 
	stack2 := make([]int, 0)
	for l1 != nil {
		stack1 = append(stack1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		stack2 = append(stack2, l2.Val)
		l2 = l2.Next
	}

	t := 0
	head := &ListNode {
		Val: -1, 
		Next: nil,
	}
	for len(stack1) > 0 || len(stack2) > 0 || t > 0 {
		if len(stack1) > 0 {
			t += stack1[len(stack1)-1]
			l1 = l1.Next
		}
		if len(stack2) > 0 {
			t += stack2[len(stack2)-1]
			l2 = l2.Next
		}
		newNode := &ListNode {
			Val: t%10,
			Next: head.Next,
		}
		head.Next = newNode
		t /= 10
	}
	return head.Next
}
// @lc code=end

