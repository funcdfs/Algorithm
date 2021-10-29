/*
 * @lc app=leetcode.cn id=110 lang=golang
 *
 * [110] 平衡二叉树
 */
package leetcode

/* --- 2021-10-29-18-07 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/balanced-binary-tree/solution/lc110-fengwei2002-by-kycu-8n9j/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans bool
func isBalanced(root *TreeNode) bool {
	ans = true
	dfs(root)
	return ans
}

func dfs(root *TreeNode) int {
	if root == nil {
		return 0
	}
	lh := dfs(root.Left)
	rh := dfs(root.Right)

	if abs(lh-rh) > 1 {
		ans = false
	}
	return max(lh, rh) + 1
}


// -----

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if (a) < 0 {
		return -a
	}
	return a
}

// @lc code=end
