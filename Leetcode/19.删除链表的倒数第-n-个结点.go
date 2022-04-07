/*
 * @lc app=leetcode.cn id=19 lang=golang
 *
 * [19] 删除链表的倒数第 N 个结点
 */
package leetcode
/* --- 2022-04-07-10-14 --- */
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
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{
		Val: -1,
		Next: head,
	}
	slow := dummy
	fast := dummy
	for i := 0; fast.Next != nil && i < n; i++ {
		fast = fast.Next
	}
    
    for slow.Next != nil && fast.Next != nil {
        slow = slow.Next 
        fast = fast.Next 
    }
    
    slow.Next = slow.Next.Next

	return dummy.Next
}
// @lc code=end

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

// 进阶：你能尝试使用一趟扫描实现吗？

 