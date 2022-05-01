/*
 * @lc app=leetcode.cn id=118 lang=golang
 *
 * [118] 杨辉三角
 */

package leetcode

/* --- 2021-10-31-14-22 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/pascals-triangle/solution/lc118-fengwei2002-by-kycu-5q8i/

// @lc code=start
func generate(numRows int) [][]int {
	f := [][]int{}

	for i := 0; i < numRows; i++ {
		line := make([]int, i+1)
		line[0], line[i] = 1, 1
		for j := 1; j < i; j++ {
			line[j] = f[i-1][j-1] + f[i-1][j]
		}
		f = append(f, line)
	}

	return f
}

// 1
// 11
// 121

// @lc code=end
