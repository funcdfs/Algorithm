/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

package leetcode

/* --- 2022-01-04-17-18 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/lc-3-fengwei2002-ha-xi-biao-by-fengwei20-nj6v/

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	ans := 0
	hash := make(map[byte]int)
	for l, r := 0, 0; r < len(s); r++ {
		hash[s[r]] += 1
		for {
			cnt, _ := hash[s[r]]
			if cnt > 1 {
				hash[s[l]] -= 1
				l++
			} else {
				break
			}
		}
		ans = max(ans, r-l+1)
	}
	return ans
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// @lc code=end
