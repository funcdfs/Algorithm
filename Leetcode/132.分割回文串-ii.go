/*
 * @lc app=leetcode.cn id=132 lang=golang
 *
 * [132] 分割回文串 II
 */
package leetcode

/* --- 2022-02-14-16-15 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 

// @lc code=start
func minCut(s string) int {
	// f[i] 表示 s[1 - i] 的所有分割方案
	// 属性是最小值

	// 状态计算：
	// f[i] 
	// 	1 - i
	//  2 - i
	//  i - i 
	//  k - i 

	n := len(s)
	


}
// @lc code=end

