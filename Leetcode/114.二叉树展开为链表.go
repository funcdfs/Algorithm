/*
 * @lc app=leetcode.cn id=114 lang=golang
 *
 * [114] 二叉树展开为链表
 */
package leetcode

/* --- 2021-10-30-23-22 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/lc114-fengwei2002-by-kycu-13h6/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start

func flatten(root *TreeNode) {
	for root != nil {
		lc := root.Left
		if lc != nil {
			for lc.Right != nil {
				lc = lc.Right
			}
			lc.Right = root.Right
			root.Right = root.Left
			root.Left = nil
		}
		root = root.Right
	}
}

// @lc code=end
