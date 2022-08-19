/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */
package leetcode

/* --- 2022-08-15-19-54 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func twoSum(nums []int, target int) []int {
	hash := make(map[int]int, 0) 
	for i := 0; i < len(nums); i++ {
		if v, ok := hash[target - nums[i]]; ok {
			return []int{i, v}
		} 
		hash[nums[i]] = i
	} 

	return []int{} 
}
// @lc code=end

