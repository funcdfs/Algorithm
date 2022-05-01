/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-12-17-24*/

// from https://github.com/fengwei2002/Algorithm
// https://leetcode.cn/problems/n-queens/solution/lc51-fengwei2002-dfs-by-kycu-clwn/

// @lc code=start
class Solution {
   private:
    int n;
    vector<bool> col, dg, udg;
    vector<vector<string>> ans;
    vector<string> board;

    void dfs(int u) {
        if (u == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                board[u][i] = 'Q';
                col[i] = dg[u - i + n] = udg[u + i] = true;

                dfs(u + 1);

                board[u][i] = '.';
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }

   public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n); // 列状态，
        dg = udg = vector<bool>(2 * n); // 对角线状态
        // 对角线是 2n - 1 条，不使用 0 值代表的对角线

        board = vector<string>(n, string(n, '.'));
        // 初始化一个 n * n 且用 点 字符填满的棋盘

        dfs(0);

        return ans;
    }
};
// @lc code=end
