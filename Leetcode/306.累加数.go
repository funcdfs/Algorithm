/*
 * @lc app=leetcode.cn id=306 lang=golang
 *
 * [306] 累加数
 */
package leetcode

import (
	"fmt"
	"strconv"
)

/* --- 2022-09-22-11-17 --- */
// https://github.com/fengwei2002/Algorithm
// @lc code=start
func isAdditiveNumber(num string) bool {
	for i := 0; i+2 < len(num); i++ {
		for j := i + 1; j+1 < len(num); j++ {
			a, b, c := -1, i, j
			for true {
				if b-a > 1 && num[a+1] == '0' || c-b > 1 && num[b+1] == '0' {
					break
				}
				x := num[a+1 : b+1]
				y := num[b+1 : c+1]
				z := add(x, y)
				if num[c+1:min(len(num), c+1+len(z))] != z {
					break
				}
				a, b, c = b, c, c+len(z)

				if c+1 == len(num) {
					return true
				}
			}
		}
	}
	return false
}

func add(x, y string) string { // 高精度可以加
	a, _ := strconv.Atoi(x)
	b, _ := strconv.Atoi(y)
	c := a + b
	return fmt.Sprintf("%d", c)
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end
