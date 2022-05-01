/*
 * @lc app=leetcode.cn id=120 lang=golang
 *
 * [120] 三角形最小路径和
 */

package leetcode

import "math"

// 2
// 3 4
// 6 5 7
// 4 1 8 3

// f[i][j] 代表 i,j 位置的距离集合，存储的值是 最短距离
// 考虑 f[i][j] 的来源
// f[i][j] = [i - 1][j - 1] + tri[i][j]
//		   = [i - 1][j] + tri[i][j]

// f[i][j] = min(f[i-1][j-1], f[i-1][j])) + tri[i][j]

/* --- 2021-10-31-14-47 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/triangle/solution/lc120-fengwei2002-by-kycu-rcxn/

// @lc code=start
func minimumTotal(triangle [][]int) int {
	n := len(triangle)
	f := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
	}
	f[0][0] = triangle[0][0]

	for i := 1; i < n; i++ {
		f[i][0] = f[i-1][0] + triangle[i][0]
		for j := 1; j < i; j++ {
			f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j]
		}
		f[i][i] = f[i-1][i-1] + triangle[i][i]
	}

	ans := math.MaxInt32
	for i := 0; i < n; i++ {
		ans = min(ans, f[n-1][i])
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// @lc code=end
