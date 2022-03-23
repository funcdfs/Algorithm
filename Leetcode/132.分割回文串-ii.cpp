/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-09-15-56*/

// https://github.com/fengwei2002/Algorithm
// solution link:
//

// @lc code=start
class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        vector<int> f(n + 1, 1e8);
        // f 数组存储最小值

        // 预处理 g 数组
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i == j)
                    g[i][j] = true;  // 只有一个字符
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || g[i + 1][j - 1]) g[i][j] = true;
                }
            }
        }

        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {  // j 枚举所有的起点
                if (g[j][i]) {
                    f[i] = min(f[i], f[j - 1] + 1);
                }
            }
        }
 
        return f[n] - 1;
    }
};
// @lc code=end

