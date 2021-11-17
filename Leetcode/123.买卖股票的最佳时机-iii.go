/*
 * @lc app=leetcode.cn id=123 lang=golang
 *
 * [123] 买卖股票的最佳时机 III
 */
package leetcode

import "math"

/* --- 2021-11-04-11-21 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/lc123-fengwei2002-by-kycu-srvo/

// @lc code=start
func maxProfit(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	f := make([]int, n+1)
	for i, minVal := 1, math.MaxInt32; i <= n; i++ {
		f[i] = max(f[i-1], prices[i-1]-minVal)
		minVal = min(minVal, prices[i-1])
	}

	ans := 0
	for i, maxVal := n, 0; i > 0; i-- {
		ans = max(ans, maxVal-prices[i-1]+f[i-1])
		maxVal = max(maxVal, prices[i-1])
	}

	return ans
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
