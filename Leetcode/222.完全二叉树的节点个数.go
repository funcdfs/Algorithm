/*
 * @lc app=leetcode.cn id=222 lang=golang
 *
 * [222] 完全二叉树的节点个数
 */
package leetcode

/* --- 2022-09-21-21-29 --- */
// https://github.com/fengwei2002/Algorithm
/*



*/

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
func countNodes(root *TreeNode) int {
	// 最后一层的所有数字都在左侧
	// 需要找到最后一层的分界点的位置
	if root == nil {
		return 0
	} 
	l := root.Left
	r := root.Right
	x, y := 1, 1 
	for l != nil {
		l = l.Left 
		x++
	} 
	for r != nil {
		r = r.Right
		y++
	} 
	// 找到左边的层数 x 和右边的层数 y

	if x == y {
		// 满二叉树 2^n - 1
		return (1 << x) - 1
	}

	// 分割为子二叉树
	return countNodes(root.Left) + 1 + countNodes(root.Right)
}
// @lc code=end

