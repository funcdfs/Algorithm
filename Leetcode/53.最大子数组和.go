/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子序和
 */
package leetcode
/* --- 2022-04-09-16-29 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func maxSubArray(nums []int) int {
	// 找出具有最大和的连续子数组 
	n := len(nums)
	f := make([]int, n + 1)
	f[0] = -1e8

	for i := 1; i <= n; i++ {
		f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1])
	}
	ans := int(-1e8)
	for _, v := range f {
		ans = max(ans,  v)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// @lc code=end

