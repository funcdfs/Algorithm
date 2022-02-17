/*
 * @lc app=leetcode.cn id=167 lang=golang
 *
 * [167] 两数之和 II - 输入有序数组
 */
package leetcode

/* --- 2022-02-17-14-40 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 

// @lc code=start
func twoSum(numbers []int, target int) []int {
	ans := make([]int, 0)
	for i, j := 0, len(numbers) - 1; i < j; i++ {
		for i < j && numbers[i] + numbers[j] > target {
			j--
		}
		if i < j && numbers[i] + numbers[j] == target {
			ans = append(ans, i + 1, j + 1)
		}
	}
	return ans
}
// @lc code=end

