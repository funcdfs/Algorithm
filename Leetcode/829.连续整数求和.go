/*
 * @lc app=leetcode.cn id=829 lang=golang
 *
 * [829] 连续整数求和
 */
package leetcode
/* --- 2022-06-07-14-02 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func consecutiveNumbersSum(n int) int {
	ans := 0 

	n *= 2 

	for b := 1; b * b <= n; b++ {
		if n % b != 0 {
			continue
		}
		if (n / b - (b - 1)) % 2 == 0 {
			ans++
		}
	}

	return ans
}
// @lc code=end

/*
begin num: a
nums count: b 

a. a+1. a+2. a+3. a+4. a+b-1

(a + (a+b-1)) * b / 2

(2a + b - 1) * b / 2 = sum(n)

2a + b - 1 = 2 * n / b

so 

2a = 2n/b - (b-1) 

a >= 1 -- a > 0 -- 2a > 0 -- 2n / b - (b - 1) > 0 

-- 2n / b > b - 1 -- 2n / b >= b

枚举 b，b 是 2n 的约数
枚举 2n 的约数，对于每一个约数 b，判断 2a = 2n/b - (b-1) 是否成立

也就是判断 [2n/b - (b-1)] / 2 是否成立
*/