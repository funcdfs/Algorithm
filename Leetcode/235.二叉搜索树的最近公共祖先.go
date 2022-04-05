/*
 * @lc app=leetcode.cn id=235 lang=golang
 *
 * [235] 二叉搜索树的最近公共祖先
 */
package leetcode

/* --- 2022-03-30-16-55 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 

type TreeNode struct {
	Val int
	Left  *TreeNode
	Right *TreeNode 
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	cur := root

	for {
		if p.Val < cur.Val && q.Val < cur.Val {
			cur = cur.Left
		} else if p.Val > cur.Val && q.Val > cur.Val {
			cur = cur.Right
		} else {
			break
		}
	}

	return cur
}
// @lc code=end

