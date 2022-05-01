/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-19-17-59*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/combinations/solution/lc77-fengwei2002-dfs-by-kycu-onsw/

// @lc code=start
class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int n, int k, int s) {
        if (k == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = s; i <= n; i++) {
            path.push_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};
// @lc code=end
