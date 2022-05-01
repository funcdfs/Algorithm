/*
 * @lc app=leetcode.cn id=191 lang=golang
 *
 * [191] 位1的个数
 */

package leetcode

/* --- 2022-01-16-12-10 --- */

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/number-of-1-bits/solution/lc191-fengwei2002-by-kycu-3exj/


// @lc code=start
func hammingWeight(n uint32) int {
	var ans int = 0
	for i := 0; i < 32; i++ {
		if ((n >> i & 1) == 1) {
			ans++
		}
	}
	return ans
}
// @lc code=end

