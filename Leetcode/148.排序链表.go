/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 */
package leetcode

/* --- 2022-02-16-22-00 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode.cn/problems/sort-list/solution/lc148-fengwei2002-by-konng0120-zzje/

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
func sortList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	n := 0
	for p := head; p != nil; p = p.Next {
		n++
	}
	dummy := &ListNode{
		Val:  -1,
		Next: head,
	}
	for subLength := 1; subLength < n; subLength <<= 1 {
		prev := dummy
		cur := dummy.Next

		for cur != nil {
			head1 := cur
			for i := 1; i < subLength && cur.Next != nil; i++ {
				cur = cur.Next
			}
			head2 := cur.Next
			cur.Next = nil

			cur = head2
			for i := 1; i < subLength && cur != nil && cur.Next != nil; i++ {
				cur = cur.Next
			}
			// 因为 cur 此时可能为空，但是要访问 cur.Next 所以判断条件要加上
			// cur != nil

			// 同理， next 的判断也不可以直接
			// next.Next = cur.Next, cur.Next = nil
			// 也需要提前判断 cur 是否非空

			next := &ListNode{
				Val:  -1,
				Next: nil,
			}

			if cur != nil {
				next.Next = cur.Next
				cur.Next = nil
			}

			mergeTwoLists := func(l1, l2 *ListNode) *ListNode {
				dummy := &ListNode{
					Val:  -1,
					Next: nil,
				}

				cur := dummy
				for l1 != nil && l2 != nil {
					if l1.Val <= l2.Val {
						cur.Next = l1
						l1 = l1.Next
					} else {
						cur.Next = l2
						l2 = l2.Next
					}
					cur = cur.Next
				}

				if l1 != nil {
					cur.Next = l1
				} else {
					cur.Next = l2
				}

				return dummy.Next
			}

			merged := mergeTwoLists(head1, head2)

			prev.Next = merged
			for prev.Next != nil {
				prev = prev.Next
			}

			cur = next.Next
		}
	}
	return dummy.Next
}

// @lc code=end
