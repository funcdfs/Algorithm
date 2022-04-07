/*
 * @lc app=leetcode.cn id=11 lang=golang
 *
 * [11] 盛最多水的容器
 */
package leetcode
/* --- 2022-04-06-19-34 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func maxArea(height []int) int {
	// 找出两条线，使得这两个线中可以放置最多的水 
	ans := 0 
	for i, j := 0, len(height) - 1; i < j; {
		ans = max(ans, min(height[i], height[j]) * (j - i))
		if height[i] > height[j] {
			j--
		} else {
			i++
		}
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	} 
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	} 
	return a
}
// @lc code=end

