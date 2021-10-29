/*
 * @lc app=leetcode.cn id=101 lang=golang
 *
 * [101] 对称二叉树
 */
package leetcode

/* --- 2021-10-25-17-46 --- */

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/symmetric-tree/solution/lc101-fengwei2002-by-kycu-ylj4/

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}
// @lc code=start
func isSymmetric(root *TreeNode) bool {
	return check(root, root)
}

func check(p, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	} else if p == nil || q == nil {
		return false
	}
	return p.Val == q.Val && check(p.Left, q.Right) && check(p.Right, q.Left)
}
// @lc code=end

