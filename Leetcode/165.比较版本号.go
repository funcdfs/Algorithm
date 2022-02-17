/*
 * @lc app=leetcode.cn id=165 lang=golang
 *
 * [165] 比较版本号
 */
package leetcode

import "strconv"

/* --- 2022-02-17-14-24 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/compare-version-numbers/solution/lc165-fengwei2002-by-konng0120-pl0v/

// @lc code=start
func compareVersion(version1 string, version2 string) int {
	for i, j := 0, 0; i < len(version1) || j < len(version2); {
		a, b := i, j
		for a < len(version1) && version1[a] != '.' {
			a++
		} 
		for b < len(version2) && version2[b] != '.' {
			b++
		}
		x, y := 0, 0
		if a != i {
			x, _ = strconv.Atoi(version1[i:i + (a - i)])
		} else {
			x = 0
		}
		if b != j {
			y, _ = strconv.Atoi(version2[j:j + (b - j)])
		} else {
			y = 0
		}

		if x > y {
			return 1
		}

		if x < y {
			return -1
		}

		i = a + 1
		j = b + 1
	}
	return 0
}

// @lc code=end
