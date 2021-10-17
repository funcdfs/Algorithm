/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-31*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/minimum-path-sum/solution/lc64-fengwei2002-dp-by-kycu-1xwa/

// @lc code=start
// 增加权值的 不同路径
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();

        vector<vector<int>> f(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j)
                    f[i][j] = grid[i][j];
                else {
                    if (i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if (j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }

        return f[n - 1][m - 1];
    }
};
// @lc code=end
