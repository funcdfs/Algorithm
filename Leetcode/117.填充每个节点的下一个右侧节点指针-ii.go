/*
 * @lc app=leetcode.cn id=117 lang=golang
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
package leetcode

import "container/list"

/* --- 2021-10-31-14-14 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/lc117-fengwei2002-by-kycu-pvjd/

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

// @lc code=start
func connect(root *Node) *Node {
	ans := [][]*Node{}
	if root == nil {
		return root
	}

	que := list.New()
	que.PushBack(root)

	for que.Len() > 0 {
		size := que.Len()
		ansItem := []*Node{}

		for i := 0; i < size; i++ {
			node := que.Remove(que.Front()).(*Node)
			ansItem = append(ansItem, node)

			if node.Left != nil {
				que.PushBack(node.Left)
			}
			if node.Right != nil {
				que.PushBack(node.Right)
			}
		}

		ans = append(ans, ansItem)
	}

	for i := 0; i < len(ans); i++ {
		for j := 0; j < len(ans[i])-1; j++ {
			ans[i][j].Next = ans[i][j+1]
		}
	}
	return root
}

// @lc code=end
