/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-13-19-13*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link: 同上一题
// https://leetcode.cn/problems/n-queens-ii/solution/lc52-fengwei2002-dfs-by-kycu-f4wm/

// @lc code=start
class Solution {
   private:
    int n;
    vector<bool> col, dg, udg;
    int ans;

    void dfs(int u) {
        if (u == n) {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = true;
                dfs(u + 1);
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }

   public:
    int totalNQueens(int _n) {
        n = _n, ans = 0;
        col = vector<bool>(n, false);
        dg = udg = vector<bool>(2 * n, false);

        dfs(0);
        return ans;
    }
};
// @lc code=end
