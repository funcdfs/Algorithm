/*
 * @lc app=leetcode.cn id=16 lang=golang
 *
 * [16] 最接近的三数之和
 */
package leetcode

/* --- 2022-04-06-21-38 --- */
// https://github.com/fengwei2002/Algorithm

import (
	"sort"
	"math"
)

// @lc code=start
func threeSumClosest(nums []int, target int) int {
	n := len(nums)
	ans := 0
	diff := math.MaxInt32
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	}) // 要先排序的话，才具有双指针的单调性

	for i := 0; i < n; i++ {
		for j, k := i + 1, n - 1; j < k; j++ {
			for j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target {
				k--
			}
			// 此时，nums[i, j, k] 和 nums[i, j, k - 1] 就是 target 边界的左右值 
			sum := nums[i] + nums[j] + nums[k]
			newDiff := abs(sum - target)
			if newDiff < diff {
				ans = sum
				diff = newDiff
			}
			if k - 1 > j {
				sum = nums[i] + nums[j] + nums[k - 1]
				newDiff = abs(sum - target)
				if newDiff < diff {
					ans = sum
					diff = newDiff
				}
			}
		}
	}
	return ans
}

func abs(a int) int { 
	if a < 0 {
		return -a
	} 
	return a
}
// @lc code=end

