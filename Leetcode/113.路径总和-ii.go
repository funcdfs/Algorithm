/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
 */

package leetcode

/* --- 2021-10-30-20-17 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/path-sum-ii/solution/lc113-fengwei2002-guan-yu-bu-li-jie-slic-hank/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start

var ans = [][]int{}

func pathSum(root *TreeNode, targetSum int) [][]int {
	ans = [][]int{}
	path := []int{}
	dfs(root, targetSum, path)
	return ans
}

func dfs(root *TreeNode, targetSum int, path []int) {
	if root == nil {
		return
	}

	targetSum -= root.Val
	path = append(path, root.Val)

	if root.Left == nil && root.Right == nil && targetSum == 0 {
		cp := make([]int, len(path))
		copy(cp, path)
		ans = append(ans, cp)
	}

	dfs(root.Left, targetSum, path)
	dfs(root.Right, targetSum, path)

	targetSum += root.Val
	path = path[:len(path)-1]
}

// @lc code=end
