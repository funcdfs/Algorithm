/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
package leetcode

/* --- 2021-10-25-17-55 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/lc102-fengwei2002-by-kycu-pkxp/

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


// 递归实现：

func DFSlevelOrder(root *TreeNode) [][]int {
    ans := make([][]int, 0)
    
    var dfs func(*TreeNode, int)
    dfs = func(cur *TreeNode, level int) {
        if cur == nil {
            return 
        }
        if level == len(ans) {
            path := make([]int, 0)
            ans = append(ans, path)
        }
        
        ans[level] = append(ans[level], cur.Val)
        dfs(cur.Left, level + 1)
        dfs(cur.Right, level + 1)
    }
    dfs(root, 0)
    return ans 
}