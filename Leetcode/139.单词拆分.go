/*
 * @lc app=leetcode.cn id=139 lang=golang
 *
 * [139] 单词拆分
 */
package leetcode

/* --- 2022-02-16-15-15 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode.cn/problems/word-break/solution/lc139-fengwei2002-by-konng0120-3m3e/

// @lc code=start
func wordBreak(s string, wordDict []string) bool {
	hash := make(map[uint64]bool)
	var P uint64 = 131
	for _, word := range wordDict {
		var h uint64 = 0
		for _, c := range word {
			h = h*P + uint64(c)
		}
		hash[h] = true
	}

	n := len(s)
	f := make([]bool, n + 1)
	f[0] = true
	for i := 0; i < n; i++ {
		if f[i] == true {
			var h uint64 = 0
			for j := i + 1; j <= n; j++ {
				h = h * P + uint64(s[j - 1])
				if v, ok := hash[h]; v == true && ok == true {
					f[j] = true
				}
			}
		}
	}

	return f[n]
}

// @lc code=end
