/*
 * @lc app=leetcode.cn id=236 lang=golang
 *
 * [236] 二叉树的最近公共祖先
 */
package leetcode

/* --- 2022-03-30-17-01 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
//
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
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	rootToP := make([]*TreeNode, 0)
	rootToQ := make([]*TreeNode, 0)

	var dfs func(*TreeNode, *TreeNode, []*TreeNode) bool
	dfs = func(cur *TreeNode, destination *TreeNode, path []*TreeNode) bool {
		if cur == nil {
			return false
		}
		if cur == destination {
			path = append(path, cur)
			return true
		}
		if dfs(cur.Left, destination, path) || dfs(cur.Right, destination, path) {
			path = append(path, cur)
			return true
		}
		return false
	}
	dfs(root, p, rootToP)
	dfs(root, q, rootToQ)

	reverse(rootToP)
	reverse(rootToQ)

	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	n := min(len(rootToP), len(rootToQ))

	for i := n - 1; i >= 0; i-- {
		if rootToP[i] == rootToQ[i] {
			return rootToP[i]
		}
	}

	return nil
}

// @lc code=end

func reverse(nums []*TreeNode) {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		tmp := nums[i]
		nums[i] = nums[j]
		nums[j] = tmp
	}
}
