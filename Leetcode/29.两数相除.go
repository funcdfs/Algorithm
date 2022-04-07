/*
 * @lc app=leetcode.cn id=29 lang=golang
 *
 * [29] 两数相除
 */
package leetcode

import "math"

/* --- 2022-04-07-13-18 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func divide(a int, b int) int {
	if a == math.MinInt32 && b == -1 {
		return math.MaxInt32
	}
	minus := 1
	if a ^ b < 0 {
		minus = -1
	}
	a, b = abs(a), abs(b)
	ans := 0
	for i := 31; i >= 0; i-- {
		if a >= b << i {
			a -= b << i
			ans += (1 << i)
		}
	}
	if minus == -1 {
		return -ans
	}
	return int(ans)
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}
// @lc code=end

