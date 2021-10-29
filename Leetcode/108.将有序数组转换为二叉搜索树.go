/*
 * @lc app=leetcode.cn id=108 lang=golang
 *
 * [108] 将有序数组转换为二叉搜索树
 */
package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/* --- 2021-10-29-17-18 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/lc108-fengwei2002-by-kycu-8eyj/

// @lc code=start

func sortedArrayToBST(n []int) *TreeNode {
	if len(n) == 0 {
		return nil
	}

	root := &TreeNode{
		Val:   n[len(n)/2],
		Left:  sortedArrayToBST(n[:len(n)/2]),
		Right: sortedArrayToBST(n[len(n)/2+1:]),
	}
	return root
}

// @lc code=end
