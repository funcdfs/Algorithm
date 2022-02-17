/*
 * @lc app=leetcode.cn id=94 lang=golang
 *
 * [94] 二叉树的中序遍历
 */
package leetcode

/* --- 2022-02-17-16-42 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/lc94-fengwei2002-by-kycu-9iye/
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
func inorderTraversal(root *TreeNode) []int {
	ans := make([]int, 0)
	stk := make([]*TreeNode, 0)

	for root != nil || len(stk) > 0 {
		for root != nil {
			stk = append(stk, root)
			root = root.Left
		}

		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]

		ans = append(ans, root.Val)
		root = root.Right
	}

	return ans
}
// @lc code=end

