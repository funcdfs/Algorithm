/*
 * @lc app=leetcode.cn id=189 lang=golang
 *
 * [189] 轮转数组
 */
package leetcode

/* --- 2022-01-16-11-19 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/rotate-array/solution/lc189-fengwei2002-by-kycu-19un/

// @lc code=start
func rotate(nums []int, k int) {
	k = k % len(nums)
	reverse(nums, 0, len(nums))
	reverse(nums, k, len(nums))
	reverse(nums, 0, k)
}

func reverse(nums []int, start int, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

// @lc code=end
