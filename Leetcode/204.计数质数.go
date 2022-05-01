/*
 * @lc app=leetcode.cn id=204 lang=golang
 *
 * [204] 计数质数
 */

package leetcode

/* --- 2022-01-17-17-42 --- */

// https://github.com/fengwei2002/Algorithm
// problem link:
// https://leetcode.cn/problems/count-primes/
// solution link:
// https://leetcode.cn/problems/count-primes/solution/lc204-fengwei2002-by-kycu-yt14/

// @lc code=start
func countPrimes(n int) int {
	primes := make([]int, 0)
	st := make([]bool, n+1)
	for i := 2; i < n; i++ {
		if st[i] == false {
			primes = append(primes, i)
		}
		for j := 0; i*primes[j] < n; j++ {
			st[i*primes[j]] = true
			if i%primes[j] == 0 {
				break
			}
		}
	}

	return len(primes)
}

// @lc code=end
