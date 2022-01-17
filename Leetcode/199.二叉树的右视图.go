/*
 * @lc app=leetcode.cn id=199 lang=golang
 *
 * [199] 二叉树的右视图
 */
package leetcode

/* --- 2022-01-16-13-19 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/lc199-fengwei2002-by-kycu-n845/

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
func rightSideView(root *TreeNode) []int {
	que := make([]*TreeNode, 0)
	ans := make([]int, 0)
	if root == nil {
		return ans
	}

	que = append(que, root)
	for len(que) > 0 {
		length := len(que)

		for i := 0; i < length; i++ {
			t := que[0]
			que = que[1:]

			if t.Left != nil {
				que = append(que, t.Left)
			}
			if t.Right != nil {
				que = append(que, t.Right)
			}
			if i == length-1 {
				ans = append(ans, t.Val)
			}
		}
	}
	return ans
}

// @lc code=end
