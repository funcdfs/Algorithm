/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
package leetcode

/* --- 2021-10-25-17-55 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/lc102-fengwei2002-by-kycu-pkxp/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
func levelOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	que := make([]*TreeNode, 0)
	que = append(que, root)

	for len(que) > 0 {
		size := len(que)
		ansItem := make([]int, 0)

		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]

			ansItem = append(ansItem, node.Val)
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
		ans = append(ans, ansItem)
	}
	return ans
}
// @lc code=end
