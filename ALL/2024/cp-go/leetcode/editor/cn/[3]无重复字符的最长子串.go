// 3 无重复字符的最长子串
// 2024-05-16 12:18:59
package main

//leetcode submit region begin(Prohibit modification and deletion)
func lengthOfLongestSubstring(s string) int {
	hs := make(map[byte]int)
	ans := 0
	left := 0
	for i := 0; i < len(s); i++ {
		hs[s[i]]++
		for left < i && hs[s[i]] > 1 {
			hs[s[left]]--
			left += 1
		}
		ans = max(ans, i - left + 1)
	}
	return ans
}
//leetcode submit region end(Prohibit modification and deletion)







