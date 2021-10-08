/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-06-23-20*/

// from https://github.com/fengwei2002/Algorithm

// @lc code=start
class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) return;

        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);

            dfs(candidates, target, sum, i);  // 这里不用 i + 1

            sum -= candidates[i];
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        path.clear();

        dfs(candidates, target, 0, 0);

        return ans;
    }
};
// @lc code=end
