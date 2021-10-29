/*
 * @lc app=leetcode.cn id=105 lang=golang
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
package leetcode

/* --- 2021-10-26-17-19 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/lc105fengwei2002-by-kycu-co7w/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) < 1 || len(inorder) < 1 {
		return nil
	}

	left := findRootIndex(preorder[0], inorder)

	root := &TreeNode{
		Val:   preorder[0],
		Left:  buildTree(preorder[1:left+1], inorder[:left]),
		Right: buildTree(preorder[left+1:], inorder[left+1:])}
	return root
}

// 3 9 20 15 7
// 9 3 15 20 7

// 在中序遍历结果中寻找 前序遍历的第一个节点，位置为 left
func findRootIndex(target int, inorder []int) int {
	for i := 0; i < len(inorder); i++ {
		if target == inorder[i] {
			return i
		}
	}
	return -1
}

// @lc code=end
