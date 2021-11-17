/*
 * @lc app=leetcode.cn id=122 lang=golang
 *
 * [122] 买卖股票的最佳时机 II
 */
package leetcode

/* --- 2021-11-01-20-34 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/lc122-fengwei2002-by-kycu-irmm/

// @lc code=start
func maxProfit(prices []int) int {
	ans := 0
	for i := 0; i < len(prices)-1; i++ {
		t := prices[i+1] - prices[i]
		if t > 0 {
			ans += t
		}
	}
	return ans
}

// @lc code=end
