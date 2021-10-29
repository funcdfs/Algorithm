/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
package leetcode

import (
	"container/list"
)

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
	que := list.New()
	que.PushBack(root)

	for que.Len() > 0 {
		size := que.Len()
		ansItem := []int{}

		for i := 0; i < size; i++ {
			node := que.Remove(que.Front()).(*TreeNode)
			ansItem = append(ansItem, node.Val)
			if node.Left != nil {
				que.PushBack(node.Left)
			}
			if node.Right != nil {
				que.PushBack(node.Right)
			}
		}
		ans = append(ans, ansItem)
		ansItem = []int{}
	}
	return ans
}

// @lc code=end
