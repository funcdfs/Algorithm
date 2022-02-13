// Problem: 正则表达式匹配
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/28/
// date: 2022-02-05 21:23:10
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/* @ https://github.com/fengwei2002/Algorithm */


class Solution {
	public:
	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		s = ' ' + s, p = ' ' + p;
		
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
		// f[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否存在一个合法方案
		
		
	}
}