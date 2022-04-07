/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
package leetcode
/* --- 2022-04-07-16-44 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	l, r := 0, len(nums) - 1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}

	if nums[l] != target {
		return []int{-1, -1}
	}
	a := l
	l, r = 0, len(nums) - 1
	for l < r {
		mid := (l + r + 1) >> 1
		if nums[mid] <= target {
			l = mid
		} else {
			r = mid - 1
		}
	}
	b := l
	return []int{a, b}
}
// @lc code=end

