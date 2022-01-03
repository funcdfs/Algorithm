/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */
package leetcode

/* --- 2022-01-02-23-16 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/add-two-numbers/solution/lc2-fengwei2002-mo-ni-gao-jing-du-jia-fa-ng51/

type ListNode struct {
	Val  int
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
	head := &ListNode{Val: -1, Next: nil}
	tail := head.Next
	// head.Next 指向的才是头节点

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

		if head.Next == nil {
			// 第一次使用 t 创建头节点：
			head.Next = &ListNode{Val: t % 10}
			tail = head.Next
		} else {
			// 之后就是 tail 向后衍生， head 不动
			tail.Next = &ListNode{Val: t % 10}
			tail = tail.Next
		}

		t /= 10
	}
	return head.Next
}

// @lc code=end
