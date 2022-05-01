/*
 * @lc app=leetcode.cn id=112 lang=golang
 *
 * [112] 路径总和
 */

package leetcode

/* --- 2021-10-30-19-42 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/path-sum/solution/lc112-fengwei2002-by-kycu-gurg/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	targetSum -= root.Val
	if root.Left == nil && root.Right == nil {
		return targetSum == 0
	}
	leftAns := hasPathSum(root.Left, targetSum)
	rightAns := hasPathSum(root.Right, targetSum)
	return leftAns || rightAns
}

// @lc code=end
