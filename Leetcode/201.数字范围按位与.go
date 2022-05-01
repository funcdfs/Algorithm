/*
 * @lc app=leetcode.cn id=201 lang=golang
 *
 * [201] 数字范围按位与
 */
package leetcode

/* --- 2022-01-16-20-42 --- */

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/bitwise-and-of-numbers-range/solution/lc201-fengwei2002-by-kycu-spio/


// @lc code=start
func rangeBitwiseAnd(left int, right int) int {
	i := 0
	for left != right { 
		left >>= 1
		right >>= 1
		i += 1
	}
	return left << i
}
// @lc code=end

