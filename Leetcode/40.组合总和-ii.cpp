/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-07-21-26*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int index) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);

            dfs(candidates, target, sum, index + 1);

            sum -= candidates[i];
            path.pop_back();
        }
    }

   public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        path.clear();

        dfs(candidates, target, 0, 0);

        return ans;
    }
};
// @lc code=end
