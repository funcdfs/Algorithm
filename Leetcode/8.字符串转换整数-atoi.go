/*
 * @lc app=leetcode.cn id=8 lang=golang
 *
 * [8] 字符串转换整数 (atoi)
 */
package leetcode

/* --- 2022-04-06-18-24 --- */
// https://github.com/fengwei2002/Algorithm

import "math"

// @lc code=start
func myAtoi(s string) int {
	index := 0 
	for index < len(s) && s[index] == ' ' {
		index++
	}
	if index == len(s) {
		return 0
	} // 去除最前面的空格 
	
	minus := 1 
	if s[index] == '-' {
		minus = -1 
		index++ 
	} else if s[index] == '+' {
		index++ 
	} // 统计前面的负号

	ans := 0 // 进行数位统计 
	for index < len(s) && s[index] >= '0' && s[index] <= '9' {
		x := int(s[index]) - int('0')

		if ans > ((math.MaxInt32 - x)/ 10) {
			if minus > 0 {
				return math.MaxInt32
			} else {
				return math.MinInt32
			}
		}
				
		ans = ans * 10 + x 
		// ans * 10 + x > math.MaxInt32
		index++ 
	}

	ans *= minus 

	return ans 
}
// @lc code=end

