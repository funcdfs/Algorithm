/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */
package leetcode

/* --- 2022-01-02-23-07 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/two-sum/solution/lc1-fengwei2002-ha-xi-biao-by-fengwei200-t94y/

// @lc code=start
func twoSum(nums []int, target int) []int {
	hash := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		another := target - nums[i]
		if pos, ok := hash[another]; ok {
			return []int{pos, i}
		}
		hash[nums[i]] = i
	}
	return nil
}

// @lc code=end
