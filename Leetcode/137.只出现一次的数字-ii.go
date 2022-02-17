/*
 * @lc app=leetcode.cn id=137 lang=golang
 *
 * [137] 只出现一次的数字 II
 */

package leetcode

/* --- 2022-02-15-11-09 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/single-number-ii/solution/lc137-fengwei2002-by-konng0120-wpsc/

// @lc code=start
func singleNumber(nums []int) int {
	var ans int32 = 0
	for i := 0; i < 32; i++ {
		sum := 0
		for _, v := range nums {
			sum += ((v >> i) & 1)
		}
		if sum%3 == 1 {
			ans |= (1 << i)
		}
	}
	return int(ans)
}

// @lc code=end
