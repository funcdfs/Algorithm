/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-22-51*/

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
    vector<bool> st;
    vector<int> path;

    void dfs(vector<int>& nums, int numCount) {
        if (numCount == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (st[i] == false) {
                st[i] = true;
                path.push_back(nums[i]);

                dfs(nums, numCount + 1);

                st[i] = false;
                path.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) st.push_back(false);
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end
