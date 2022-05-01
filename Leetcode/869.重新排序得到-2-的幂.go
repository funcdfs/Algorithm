/*
 * @lc app=leetcode.cn id=869 lang=golang
 *
 * [869] 重新排序得到 2 的幂
 */
package leetcode

import (
	"strconv"
)

/* --- 2021-10-28-15-08 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/reordered-power-of-2/solution/lc869-fengwei2002-by-kycu-xz2t/

// @lc code=start
func reorderedPowerOf2(n int) bool {
	s := strconv.Itoa(n)
	countS := make([]int, 10, 10)

	for i := 0; i < len(s); i++ {
		countS[s[i]-'0']++
	}

	for i := 0; i < 31; i++ {
		t := strconv.Itoa(1 << i)
		if len(t) == len(s) && check(countS, t) {
			return true
		}
	}

	return false
}

func check(countS []int, t string) bool {
	countT := make([]int, 10, 10)

	for i := 0; i < len(t); i++ {
		countT[t[i]-'0']++
	}

	for i := 0; i < 10; i++ {
		if countS[i] != countT[i] {
			return false
		}
	}

	return true
}

// @lc code=end
