/*
 * @lc app=leetcode.cn id=991 lang=golang
 *
 * [991] 坏了的计算器
 */
package leetcode

/* --- 2021-11-04-11-35 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
//

// @lc code=start
func brokenCalc(startValue int, target int) int {
	// 考虑 下降的速度，除 2 比减 1 下降快
	ans := 0
	for startValue*2 < target {
		startValue *= 2
		ans++
	}
	b := startValue * 2
	ans++
	
	stepB := 0

	for b > target {
		b--
		stepB++
	}
	return ans + stepB
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end
