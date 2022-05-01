/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111] 二叉树的最小深度
 */

package leetcode

/* --- 2021-10-31-13-55 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/solution/lc111-fengwei2002-by-kycu-y68q/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right != nil {
		return 1 + minDepth(root.Right)
	}
	if root.Left != nil && root.Right == nil {
		return 1 + minDepth(root.Left)
	}
	return min(minDepth(root.Left), minDepth(root.Right)) + 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end
