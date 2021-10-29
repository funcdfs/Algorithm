/*
 * @lc app=leetcode.cn id=104 lang=golang
 *
 * [104] 二叉树的最大深度
 */
package leetcode

/* --- 2021-10-26-17-08 --- */

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/lc104-fengwei2002-by-kycu-7p9e/

type TreeNode struct {
	Val int
	Left *TreeNode
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
func maxDepth(root *TreeNode) int {
	ans := 0
	if root == nil {
		return ans
	}
	ans = dfs(root)
	return ans
}

func dfs(root *TreeNode) int {
	if root.Left == nil && root.Right == nil {
		return 1
	}
	if root.Left != nil && root.Right == nil {
		return dfs(root.Left) + 1
	}
	if root.Left == nil && root.Right != nil {
		return dfs(root.Right) + 1
	}
	return max(dfs(root.Left), dfs(root.Right)) + 1
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
// @lc code=end

