/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */
package leetcode
/* --- 2022-04-06-16-59 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func longestPalindrome(s string) string {
	ans := make([]byte, 0) 
	str := []byte(s) 
	
	for i := 0; i < len(str); i++ {
		// 枚举所有的起始下标 

		// 枚举所有奇数长度的字符串 
		l, r := i - 1, i + 1 
		for l >= 0 && r < len(str) && l < r && s[l] == s[r] {
			l-- 
			r++ 
		}
		l++
		r--
		ansLength := r - l + 1
		if len(ans) < ansLength {
			ans = str[l:l+ansLength]
		}

		// 枚举当前起始下标的长度为偶数的字符串 
		l, r = i, i+1
		for l >= 0 && r < len(str) && l < r && s[l] == s[r] {
			l--
			r++ 
		}
		l++
		r--
		ansLength = r - l + 1 
		if len(ans) < ansLength {
			ans = str[l:l+ansLength]
		}
	}

	return string(ans)
}
// @lc code=end

