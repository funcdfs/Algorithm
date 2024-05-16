// 2 两数相加
// 2024-05-16 11:42:50
package main

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	tail := head
	t := 0
	for t > 0 || l1 != nil || l2 != nil {
		if l1 != nil {
			t += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			t += l2.Val
			l2 = l2.Next
		}
		if head.Next == nil {
			head.Next = &ListNode{Val: t % 10}
			tail = head.Next
		} else {
			tail.Next = &ListNode{Val: t % 10}
			tail = tail.Next
		}
		t /= 10
	}
	return head.Next
}

//leetcode submit region end(Prohibit modification and deletion)

type ListNode struct {
	Val  int
	Next *ListNode
}
