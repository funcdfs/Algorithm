/*
 * @lc app=leetcode.cn id=115 lang=golang
 *
 * [115] 不同的子序列
 */

package leetcode

/* --- 2021-10-31-10-18 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/distinct-subsequences/solution/lc115-fengwei2002-by-kycu-6xrr/

// @lc code=start
func numDistinct(s1 string, s2 string) int {
	n, m := len(s1), len(s2)
	f := make([][]int64, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int64, m+1)
	}

	for i := 0; i <= n; i++ {
		f[i][0] = 1
		// f[i][0] 可以代表 s1[1...i] 中一个都不选，s2 中选择 0 个。是一种合法方案
		// 所以这里初始化 所有的 f[i][0] 为 1，而不是 0 
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				f[i][j] = f[i-1][j] + f[i-1][j-1]
			} else if s1[i-1] != s2[j-1] {
				f[i][j] = f[i-1][j]
			}
		}
	}

	return int(f[n][m])
}

// @lc code=end
