/*
 * @lc app=leetcode.cn id=31 lang=golang
 *
 * [31] 下一个排列
 */

package leetcode
/* --- 2022-04-07-14-47 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func nextPermutation(nums []int)  {
	k := len(nums) - 1
	for k > 0 && nums[k - 1] >= nums[k] {
		k--
	}
	// 从前往后找到第一个当前数字小于后面数字的一个数字对 
	// 此时 nums[k - 1] 和 nums[k] 就是 nums[k - 1] < nums[k]

	if k == 0 {
		// 说明此时数组全部逆序，没有找到满足要求的 K (k == 0)
		// 就说明当前已经是最大的排列
		// 那么此时要返回最小的排列，也就是将 nums 逆序 
		for i, j := 0, len(nums) - 1; i < j; i, j = i+1, j-1 {
			nums[i], nums[j] = nums[j], nums[i]
		}
	} else {
		// 在 nums[k] 后面找到最小的比 nums[k - 1] 大的数字 
		t := k
		for t < len(nums) && nums[t] > nums[k - 1] {
			t++
		}
		nums[k - 1], nums[t - 1] = nums[t - 1], nums[k - 1]
		for i, j := k, len(nums) - 1; i < j; i, j = i + 1, j-1 {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
}
// @lc code=end

