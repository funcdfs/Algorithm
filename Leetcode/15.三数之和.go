/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */
package leetcode

import (
	"sort"
)

/* --- 2022-04-06-21-07 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func threeSum(nums []int) [][]int {
	ans := make([][]int, 0)
	n := len(nums)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	for i := 0; i < n; i++ {
		if i > 0 && nums[i] == nums[i - 1] {
			continue
		}
		for j, k := i + 1, len(nums) - 1; j < k; j++ {
			if j > i + 1 && nums[j] == nums[j - 1] {
				continue
			}
			for j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0 {
				k--
			}
			if nums[i] + nums[j] + nums[k] == 0 {
				ans = append(ans, []int{nums[i], nums[j], nums[k]})
			}
		}
	}
	return ans
}
// @lc code=end

