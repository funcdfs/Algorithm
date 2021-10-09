/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-23-05*/

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
    vector<bool> st;

    void dfs(vector<int>& nums, int numCount) {
        if (numCount == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (st[i] == false) {
                if (i && nums[i - 1] == nums[i] && st[i - 1] == false) continue;
                
                st[i] = true;
                path[numCount] = nums[i];

                dfs(nums, numCount + 1);

                st[i] = false;
            }
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0);

        return ans;
    }
};
// @lc code=end
