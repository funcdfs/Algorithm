/*
 * @lc app=leetcode.cn id=209 lang=golang
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (46.75%)
 * Likes:    727
 * Dislikes: 0
 * Total Accepted:    172.8K
 * Total Submissions: 369.5K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不,存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 *
 *
 */
package leetcode

/* --- 2022-01-20-21-21 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode.cn/problems/minimum-size-subarray-sum/solution/lc209-fengwei2002-by-kycu-mfnn/

// @lc code=start
func minSubArrayLen(target int, nums []int) int {
	// 找出数组中和大于等于 target 的长度最小的子数组
	ans := (int)(1e9)
	for i, j, sum := 0, 0, 0; i < len(nums); i++ {
		sum += nums[i]
		for sum-nums[j] >= target {
			sum -= nums[j]
			j++
		}
		if sum >= target {
			ans = min(ans, i-j+1)
		}
	}
	if ans == (int)(1e9) {
		ans = 0
	}
	return ans
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// @lc code=end
