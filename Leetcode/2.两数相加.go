/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */
package leetcode

/* --- 2022-04-06-16-12 --- */

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
	ans := &ListNode{
		Val: -1, 
		Next: nil, 
	}
	dummy := ans
	t := 0 
	
	for l1 != nil || l2 != nil || t > 0 {
		if l1 != nil {
			t += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			t += l2.Val
			l2 = l2.Next
		}

		ans.Next = &ListNode{
			Val: t % 10,
			Next: nil, 
		}
		ans = ans.Next
		t /= 10
	}

	return dummy.Next
}
// @lc code=end

