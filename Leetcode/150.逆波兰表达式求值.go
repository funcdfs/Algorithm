/*
 * @lc app=leetcode.cn id=150 lang=golang
 *
 * [150] 逆波兰表达式求值
 */
package leetcode

import "strconv"

/* --- 2022-02-17-14-02 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
//

// @lc code=start
func evalRPN(tokens []string) int {
	stk := make([]int, 0)
	for _, s := range tokens {
		if s == "+" || s == "-" || s == "*" || s == "/" {
			b := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			a := stk[len(stk)-1]
			stk = stk[:len(stk)-1]

			if s == "+" {
				a += b
			} else if s == "-" {
				a -= b
			} else if s == "*" {
				a *= b
			} else if s == "/" {
				a /= b
			}

			stk = append(stk, a)
		} else {
			num, _ := strconv.Atoi(s)
			stk = append(stk, num)
		}
	}

	return stk[len(stk)-1]
}

// @lc code=end
