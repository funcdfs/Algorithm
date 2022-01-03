/*
 * @lc app=leetcode.cn id=131 lang=golang
 *
 * [131] 分割回文串
 */
package leetcode

/* --- 2021-11-19-16-40 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
//

// @lc code=start

var f [][]bool
var ans [][][]string
var path [][]string

func partition(s string) [][]string {
	// f[i][j] 表示 字符串的 i 到 j 是否是一个回文串
	// 状态属性是 bool 代表是否存在
	// f[i][j] = s[i] == s[j] && f[i + 1][j - 1] == true
	n := len(s)

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if i == j {
				f[i][j] = true // 只有一个字符的话他是一个回文串
			} else if s[i] == s[j] {
				if f[i+1][j-1] == true || ((j-1)-(i+1) < 0) {
					f[i][j] = true
				}
			}
		}
	}

	dfs(s, 0)
}

func dfs(s string, u int) {
	if u == len(s) {
		ans = append(ans, path)
	} else {
		for i := u; i < len(s); i++ {
			if (f[u][i] == true) {
				path.push_back(s.substr(u, i - u + 1));
				dfs(s, i + 1);
				path.pop_back();
			}
		}
	}
}

// @lc code=end
