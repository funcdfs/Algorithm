// 5 最长回文子串
// 2024-05-16 12:56:50
package main

// leetcode submit region begin(Prohibit modification and deletion)
func longestPalindrome(s string) string {
	ans := ""
	l, r := 0, 0
	for i, n := 0, len(s); i < n; i++ {
		l, r = i, i
		for l >= 0 && r < n && s[l] == s[r] {
			l--
			r++
		}
		l++
		r--
		if r-l+1 > len(ans) {
			ans = s[l : l+(r-l+1)]
		}

		l, r = i, i+1
		for l >= 0 && r < n && s[l] == s[r] {
			l--
			r++
		}
		l++
		r--
		if r-l+1 > len(ans) {
			ans = s[l : l+(r-l+1)]
		}
	}
	return ans
}

//leetcode submit region end(Prohibit modification and deletion)
