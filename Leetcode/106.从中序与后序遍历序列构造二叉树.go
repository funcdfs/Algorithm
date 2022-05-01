/*
 * @lc app=leetcode.cn id=106 lang=golang
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
package leetcode

/* --- 2021-10-29-11-02 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/lc106-fengwei2002-by-kycu-8h26/
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

func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) < 1 || len(postorder) < 1 {
		return nil
	}

	left := find(inorder, postorder[len(postorder)-1])

	root := &TreeNode{
		Val:   postorder[len(postorder)-1],
		Right: buildTree(inorder[left+1:], postorder[left:len(postorder)-1]),
		Left:  buildTree(inorder[0:left], postorder[0:left])}

	return root
}

func find(inorder []int, t int) int {
	for i := 0; i < len(inorder); i++ {
		if t == inorder[i] {
			return i
		}
	}
	return -1
}

// @lc code=end
