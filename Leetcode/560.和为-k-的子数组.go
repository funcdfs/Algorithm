/*
 * @lc app=leetcode.cn id=560 lang=golang
 *
 * [560] 和为 K 的子数组
 */
package leetcode

/* --- 2021-11-05-10-24 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
//

// @lc code=start
func subarraySum(nums []int, k int) int {
	count := 0
	
	return count
}

// @lc code=end

func forceFor(nums []int, k int) int {
	count := 0
	for start := 0; start < len(nums); start++ {
		sum := 0
		for end := start; end >= 0; end-- {
			sum += nums[end]
			if sum == k {
				count++
			}
		}
	}
	return count
}

