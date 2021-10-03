/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-01-21-20*/

//from https://github.com/fengwei2002/Algorithm
/* 
 !
 ! a b c d 互不相同的四元组
 *
 * 注意去重的写法
 */


// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    if (nums[i] + nums[j] > target - (nums[k] + nums[l])) {
                        l--;
                    } else if (nums[i] + nums[j] + nums[k] + nums[l] < target) {
                        k++;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        while (k < l && nums[l] == nums[l - 1]) l--;
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        l--, k++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
