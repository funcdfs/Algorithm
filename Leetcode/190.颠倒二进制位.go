/*
 * @lc app=leetcode.cn id=190 lang=golang
 *
 * [190] 颠倒二进制位
 */
package leetcode

/* --- 2022-01-16-11-52 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/reverse-bits/solution/lc190-fengwei2002-by-kycu-9sor/

// @lc code=start
func reverseBits(num uint32) uint32 {
	var ans uint32 = 0
	for i := 0; i < 32; i++ {
		ans = (ans << 1) + (num >> i & 1)
	}
	return uint32(ans)
}

// @lc code=end
