/*
 * @lc app=leetcode.cn id=172 lang=golang
 *
 * [172] 阶乘后的零
 */
package leetcode

/* --- 2022-02-17-14-45 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/lc172-fengwei2002-by-konng0120-ikh1/

// @lc code=start
func trailingZeroes(n int) int {
	ans := 0
	for n > 0 {
		ans += n / 5
		n /= 5
	}
	return ans
}

// @lc code=end
