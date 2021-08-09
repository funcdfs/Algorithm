/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-09-11-42*/
// ? 思路解析：
/*
 *
 *
 *
 *
 ! --难点：
 ! --
 ! --
 */

// @lc code=start
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// @lc code=end

class DFS {
   private:
    int dfs(int i, int j, int m, int n) {
        if (i > m || j > n) return 0;  // 越界了
        if (i == m && j == n) return 1;  // 找到一种方法，相当于找到了叶子节点
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }

   public:
    int uniquePaths(int m, int n) { return dfs(1, 1, m, n); }
};

class oneDimensional {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
