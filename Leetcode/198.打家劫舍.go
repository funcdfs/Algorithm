/*
 * @lc app=leetcode.cn id=198 lang=golang
 *
 * [198] 打家劫舍
 */
package leetcode

/* --- 2022-01-16-12-13 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/house-robber/solution/lc198-fengwei2002-by-kycu-3qst/

// @lc code=start
func rob(nums []int) int {
	n := len(nums)
	f := make([]int, n+1)
	g := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = g[i-1] + nums[i-1]
		g[i] = max(f[i-1], g[i-1])
	}
	return max(f[n], g[n])
}

func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

// @lc code=end
