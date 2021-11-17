/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机
 */

package leetcode

import "math"

/* --- 2021-11-01-09-43 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/lc121-fengwei2002-by-kycu-38dw/

// @lc code=start
func maxProfit(prices []int) int {
	ans := 0
	minVal := math.MaxInt32
	for _, v := range prices {
		minVal = min(minVal, v)
		ans = max(ans, v-minVal)
	}
	return ans
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
