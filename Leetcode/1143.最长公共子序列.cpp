/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include <iostream>
#include <vector>
using namespace std;
// date: 2021-08-13
// @lc code=start

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i - 1] == text2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            }
        return f[m][n];
    }
};
// @lc code=end
