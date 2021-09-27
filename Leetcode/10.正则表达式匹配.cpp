/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-27-17-35*/

// from https://github.com/fengwei2002/Algorithm
/*
 !https://leetcode-cn.com/problems/regular-expression-matching/solution/lc10zheng-ze-biao-da-shi-pi-pei-by-fengw-zjz3/
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;  //为了下标从 1 开始

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true; // 当第一个字符串和第二个字符串都是空串的时候，视为匹配

        // 第一个串为空时，可能匹配，因为 'x*' 可匹配零个，所以 i 可从 0 开始
        // 所以第一个字符串为 0 第二个字符串不为 0 的时候可以存在
        // f[1,0] 一定不匹配，所以 j 要从 1 开始

        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                // 遇到 x* 视为一个整体
                if (j + 1 < p.size() && p[j + 1] == '*') continue;

                // 第一种情况和第二种情况
                if (i && p[j] != '*') { // 因为存在 i == 0 的情况计算 i - 1，所以要加上 i &&
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') {
                    f[i][j] = f[i][j - 2] ||
                              i && f[i - 1][j] &&
                                  (s[i] == p[j - 1] || p[j - 1] == '.'); 
                    // 这里 s[i] 和 p[j - 1] 匹配。因为 p[j] 是 * p[j- 1] 才是代表的字符
                }  //&&优先级 > || 
            }

        return f[n][m];
    }
};
// @lc code=end

class Solution1 {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 < m && p[j + 1] == '*') continue;

                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') {
                    f[i][j] = (f[i][j - 2]) || ((i && f[i - 1][j]) 
                    && (s[i] == p[j - 1] || p[j - 1] == '.')); 
                }
            }
        }
        return f[n][m];
    }
};