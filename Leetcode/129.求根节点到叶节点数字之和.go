/*
 * @lc app=leetcode.cn id=129 lang=golang
 *
 * [129] 求根节点到叶节点数字之和
 */
package leetcode

import (
	"strconv"
)

/* --- 2021-11-19-14-58 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/sum-root-to-leaf-numbers/solution/lc129-fengwei2002-by-kycu-2anv/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start

var stringArray []string

func sumNumbers(root *TreeNode) int {
	// 计算所有路径生成的数字的 和
	ans := 0
	stringArray = make([]string, 0)

	dfs(root, strconv.Itoa(root.Val))

	for _, v := range stringArray {
		t, _ := strconv.Atoi(v)
		ans += t
	}
	return ans
}

func dfs(root *TreeNode, path string) {
	if root.Left == nil && root.Right == nil {
		stringArray = append(stringArray, path)
		return
	}

	if root.Left != nil {
		path += strconv.Itoa(root.Left.Val)
		dfs(root.Left, path)
		path = path[:len(path)-1]
	}
	if root.Right != nil {
		path += strconv.Itoa(root.Right.Val)
		dfs(root.Right, path)
		path = path[:len(path)-1]
	}

	return
}

// @lc code=end
