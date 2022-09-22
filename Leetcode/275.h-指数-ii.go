/*
 * @lc app=leetcode.cn id=275 lang=golang
 *
 * [275] H 指数 II
 */
package leetcode

/* --- 2022-09-21-23-18 --- */
// https://github.com/fengwei2002/Algorithm
/*



 */
// @lc code=start
func hIndex(citations []int) int {
	n := len(citations)
	l, r := 0, n
	for l < r {
		mid := (l + r + 1) >> 1
		if citations[n-mid] >= mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}

// @lc code=end
