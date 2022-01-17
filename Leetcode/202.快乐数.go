/*
 * @lc app=leetcode.cn id=202 lang=golang
 *
 * [202] 快乐数
 */
package leetcode

/* --- 2022-01-16-20-46 --- */

// https://github.com/fengwei2002/Algorithm
// problem link:
// https://leetcode-cn.com/problems/happy-number/
// solution link: 
// https://leetcode-cn.com/problems/happy-number/solution/lc202-fengwei2002-by-kycu-oq94/


// @lc code=start
func isHappy(n int) bool {
	slow := n
	fast := n
	slow = get(n)
	fast = get(get(n))
	for slow != fast {
		slow = get(slow)
		fast = get(get(fast))
	}
	return slow == 1
}

func get(x int) int { 
	ans := 0
	for x != 0 {
		ans += (x % 10) * (x % 10)
		x /= 10
	}
	return ans
}
// @lc code=end

