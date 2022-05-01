/*
 * @lc app=leetcode.cn id=107 lang=golang
 *
 * [107] 二叉树的层序遍历 II
 */

package leetcode

import "container/list"

/* --- 2021-10-29-12-00 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solution/lc107-fengwei2002-by-kycu-0dzf/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
func levelOrderBottom(root *TreeNode) [][]int {
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
	}
	reverse(ans)
	return ans
}

func reverse(a [][]int) {
	l, r := 0, len(a)-1
	for l < r {
		a[l], a[r] = a[r], a[l]
		l, r = l+1, r-1
	}
}

// @lc code=end
