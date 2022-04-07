/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */
package leetcode

/* --- 2022-04-06-16-21 --- */

// https://github.com/fengwei2002/Algorithm

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	// 大概思路就是维护一个动态的滑动窗口哈希表
	hash := make(map[byte]int, 0)
	ans := 0
	for l, r := 0, 0; r < len(s); r++ {
		hash[s[r]] += 1 
		for {
			cnt, _ := hash[s[r]]
			if cnt > 1 {
				hash[s[l]] -= 1
				l += 1
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
