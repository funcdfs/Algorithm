/*
 * @lc app=leetcode.cn id=10 lang=golang
 *
 * [10] 正则表达式匹配
 */
package leetcode
/* --- 2022-06-07-13-41 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func isMatch(ss string, pp string) bool {
	s := []rune(ss) 
	p := []rune(pp) 
	n := len(s) 
	m := len(p) 

	s = append([]rune{' '}, s...)
	p = append([]rune{' '}, p...)

	f := make([][]bool, n + 1)
	for i := 0; i < n + 1; i++ {
		f[i] = make([]bool, m + 1)
	}

	f[0][0] = true

	for i := 0; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if j + 1 <= m && p[j + 1] == '*' {
				continue
			}
			if i > 0 && p[j] != '*' {
				f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.')
			} else if p[j] == '*' {
				f[i][j] = f[i][j - 2] || i > 0 && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.')
			}
		}
	}

	return f[n][m]
}
// @lc code=end

/*
f[i][j] 代表 s 的前 i 个字符和 j 的前 j 个字符匹配的所有方案
属性：是否存在一个方案 

考虑状态来源 f[i][j]:

if s[i] == p[j] || p[j] == '.':
	f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[i] == '.')
else: if p[j] == '*':
	f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.')
*/