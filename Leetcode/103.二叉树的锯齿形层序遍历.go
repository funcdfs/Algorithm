/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
 */
package leetcode

import "container/list"

/* --- 2021-10-26-16-44 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/lc103-fengwei2002-by-kycu-19d9/

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
func zigzagLevelOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	right := false

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
		if right == true {
			reverse(ansItem)
			ans = append(ans, ansItem)
			right = !right
		} else if right == false {
			ans = append(ans, ansItem)
			right = !right
		}
	}
	return ans
}

func reverse(nums []int) {
	l, r := 0, len(nums)-1
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
}

// @lc code=end
