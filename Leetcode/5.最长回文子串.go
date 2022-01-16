/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */
package leetcode

/* --- 2022-01-07-21-06 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/lc5-fengwei2002-shuang-zhi-zhen-by-fengw-rdy2/

/*
 * 枚举所有中点值，当左右索引下标都不越界，并且满足相等的条件
            就继续扩大 左右索引下标的范围，
            奇数和偶数的字符串，分别判断一次
*/
// @lc code=start
func longestPalindrome(s string) string {
	ans := ""

	for i := 0; i < len(s); i++ {
		// 如果答案长度是奇数
		l, r := i-1, i+1
		for l >= 0 && r < len(s) && l < r && s[l] == s[r] {
			l--
			r++
		}
		ansLength := r - l + 1 - 2
		if len(ans) < ansLength {
			ans = s[l+1 : l+1+ansLength]
		}

		// 如果答案是偶数
		l, r = i, i+1
		for l >= 0 && r < len(s) && l < r && s[l] == s[r] {
			l--
			r++
		}
		ansLength = r - l + 1 - 2
		if len(ans) < ansLength {
			ans = s[l+1 : l+1+ansLength]
		}
	}
	return ans
}

// @lc code=end
