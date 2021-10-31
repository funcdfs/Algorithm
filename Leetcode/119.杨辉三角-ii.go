/*
 * @lc app=leetcode.cn id=119 lang=golang
 *
 * [119] 杨辉三角 II
 */

package leetcode

/* --- 2021-10-31-14-33 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/pascals-triangle-ii/solution/lc119-fengwei2002-by-kycu-nfcf/

// @lc code=start
func getRow(rowIndex int) []int {
	f := make([][]int, 2)
	for i := 0; i < 2; i++ {
		f[i] = make([]int, rowIndex+1)
	}
	// 首先不用滚动数组解决这个问题，然后对数组的行 index 进行修改
	// 第 0 行存储 0 2 4 6 8 10 行
	// 第 1 行存储 1 3 5 7 9 行
	// 第 n 行应该存储到 n % 2 行，也就是 & 1 的地方

	for i := 0; i <= rowIndex; i++ {
		f[i&1][0], f[i&1][i] = 1, 1
		for j := 1; j < i; j++ {
			f[i&1][j] = f[(i-1)&1][j-1] + f[(i-1)&1][j]
		}
	}
	return f[rowIndex&1]
}

// @lc code=end
