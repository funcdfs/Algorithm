/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
 */
package leetcode

/* --- 2021-10-26-16-44 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/solution/lc103-fengwei2002-by-kycu-19d9/

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
    ans := make([][]int, 0) 
    que := make([]*TreeNode, 0)
    if root == nil {
        return ans 
    }
    
    flag := 0 
    
    que = append(que, root)
    for len(que) > 0 {
        flag += 1 
        length := len(que) 
        path := make([]int, 0) 
        
        for i := 0; i < length; i++ {
            t := que[0] 
            que = que[1:]
            path = append(path, t.Val)
            
            if t.Left != nil {
                que = append(que, t.Left)
            }
            if t.Right != nil {
                que = append(que, t.Right)
            }
        }
        if flag % 2 == 0 {
            for i, j := 0, len(path) - 1; i < j; i, j = i + 1, j - 1 {
                path[i], path[j] = path[j], path[i]
            }
        } // 可以扩展到三层一次，n 叉树
        ans = append(ans, path)
    }
    
    return ans
}

// @lc code=end
