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

// @lc code=start

class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& nums, int target, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            // 如果不选择当前数字则跳过所有数字，树的每一层只选择一个
            if (i > startIndex && nums[i] == nums[i - 1]) continue;

            sum += nums[i];
            path.push_back(nums[i]);
            dfs(nums, target, sum, i + 1);
            // 同一个数字下标在一个树枝中只用一次

            path.pop_back();
            sum -= nums[i];
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};
// @lc code=end
