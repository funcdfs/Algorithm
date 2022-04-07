/*
 * @lc app=leetcode.cn id=18 lang=golang
 *
 * [18] 四数之和
 */
package leetcode

import "sort"

/* --- 2022-04-07-10-02 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func fourSum(nums []int, target int) [][]int {
	n := len(nums)
	ans := make([][]int, 0)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	for i := 0; i < n; i++ {
		if i > 0 && nums[i] == nums[i - 1] {
			continue
		}
		for j := i + 1; j < n; j++ {
			if j > i + 1 && nums[j] == nums[j - 1] {
				continue
			}
			for k, l := j + 1, n - 1; k < l; k++ {
				if k > j + 1 && nums[k] == nums[k - 1] {
					continue
				}
				for k < l - 1 && nums[i] + nums[j] + nums[k] + nums[l - 1] >= target {
					l--
				}
				if nums[i] + nums[j] + nums[k] + nums[l] == target {
					ans = append(ans, []int{nums[i], nums[j], nums[k], nums[l]})
				}
			}
		}
	}
	return ans
}
// @lc code=end

