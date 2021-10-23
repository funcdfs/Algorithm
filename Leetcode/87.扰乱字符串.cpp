/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-01*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/scramble-string/solution/lc87-fengwei2002-by-kycu-obql/

// @lc code=start
class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> f(
            n, vector<vector<bool>>(n, vector<bool>(n + 1)));

        for (int k = 1; k <= n; k++) {
            for (int i = 0; i + k - 1 < n; i++) {
                for (int j = 0; j + k - 1 < n; j++) {
                    if (k == 1) {
                        if (s1[i] == s2[j]) f[i][j][k] = true;
                    } else {
                        for (int u = 1; u < k; u++) {
                            if (f[i][j][u] && f[i + u][j + u][k - u] ||
                                f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return f[0][0][n];
        // 第一个字符串从 0 开始，第二个字符串从 0 开始，长度是 n
    }
};
// @lc code=end
