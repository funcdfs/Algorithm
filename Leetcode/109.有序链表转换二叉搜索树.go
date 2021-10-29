/*
 * @lc app=leetcode.cn id=109 lang=golang
 *
 * [109] 有序链表转换二叉搜索树
 */
package leetcode

/* --- 2021-10-29-17-41 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/lc109-fengwei2002-by-kycu-smfq/

type ListNode struct {
	Val  int
	Next *ListNode
}
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
func sortedListToBST(head *ListNode) *TreeNode {
	tmpArr := []int{}
	for head != nil {
		tmpArr = append(tmpArr, head.Val)
		head = head.Next
	}
	return BST(tmpArr)
}

func BST(a []int) *TreeNode {
	if len(a) == 0 {
		return nil
	}

	root := &TreeNode{
		Val:   a[len(a)/2],
		Left:  BST(a[0 : len(a)/2]),
		Right: BST(a[len(a)/2+1:]),
	}
	return root
}

// @lc code=end
