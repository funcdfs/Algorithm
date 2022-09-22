/*
 * @lc app=leetcode.cn id=223 lang=golang
 *
 * [223] 矩形面积
 */
package leetcode

/* --- 2022-09-21-21-55 --- */
// https://github.com/fengwei2002/Algorithm
/*

两个矩形的覆盖的总面积

*/
// @lc code=start
func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	area1 := (ax2 - ax1) * (ay2 - ay1)
	area2 := (bx2 - bx1) * (by2 - by1)

	// A B, C D
	overlapWidth := min(ax2, bx2) - max(ax1, bx1)
	overlapHight := min(ay2, by2) - max(ay1, by1)
	overlapArea := max(overlapWidth, 0) * max(overlapHight, 0)
	return area1 + area2 - overlapArea
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end
