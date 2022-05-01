/*
 * @lc app=leetcode.cn id=540 lang=golang
 *
 * [540] 有序数组中的单一元素
 */
package leetcode

/* --- 2022-02-14-13-44 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode.cn/problems/single-element-in-a-sorted-array/solution/lc540-fengwei2002-by-konng0120-v64w/

// @lc code=start
func singleNonDuplicate(nums []int) int {
	nums = append(nums, nums[len(nums)-1]+1)
	l, r := 0, int(len(nums)/2)
	for l < r {
		mid := (l + r) >> 1
		if nums[mid*2] != nums[mid*2+1] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[r*2]
}

// @lc code=end
