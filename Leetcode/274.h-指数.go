/*
 * @lc app=leetcode.cn id=274 lang=golang
 *
 * [274] H 指数
 */
package leetcode

import "sort"

/* --- 2022-09-21-22-47 --- */
// https://github.com/fengwei2002/Algorithm
/*



 */
// @lc code=start
func hIndex(citations []int) int {
	sort.Slice(citations, func(i, j int) bool {
		return citations[i] > citations[j]
	})
	for h := len(citations); h > 0; h-- {
		if citations[h - 1] >= h {
			return h
		}
	}

	return 0
}

// @lc code=end
