/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-21*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/unique-paths-ii/solution/lc63-fengwei200-dp-by-kycu-4oc4/

// @lc code=start
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));

        for (int i = 0; i < n && board[i][0] == 0; i++) f[i][0] = 1;
        for (int j = 0; j < m && board[0][j] == 0; j++) f[0][j] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (board[i][j] == 1) continue;
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

// @lc code=end
