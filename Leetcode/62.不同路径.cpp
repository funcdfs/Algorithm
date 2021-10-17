/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-02*/

// depository: 
// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/unique-paths/solution/lc62-fengwei2002-dp-by-kycu-nw8y/


// @lc code=start
// DP
class Solution {
   public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> f(n, vector<int>(m, 0));
        // 代表到达 map[n][m] 位置的路径个数
        for (int i = 0; i < n; i++) f[i][0] = 1;
        for (int j = 0; j < m; j++) f[0][j] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

// @lc code=end

// 超时 dfs

class Solution {
   private:
    int n, m;
    int dfs(int i, int j) {
        if (i > n || j > m) return 0;
        if (i == n && j == m) return 1;
        return dfs(i + 1, j) + dfs(i, j + 1);
    }

   public:
    int uniquePaths(int _n, int _m) {
        n = _n, m = _m;
        return dfs(1, 1);
    }
};