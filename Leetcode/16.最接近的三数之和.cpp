/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-30-10-34*/

//from https://github.com/fengwei2002/Algorithm
/* 
 !  注意根据距离更新 ans 的写法，剩下的代码 和三数之和一模一样
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) continue; 

            int k = n - 1;
            int j = i + 1;

            while (j < k) {
                // 注意这三行根据距离更新 ans 的方式
                int dummy = nums[i] + nums[j] + nums[k];
                if (abs(dummy - target) < abs(ans - target))
                    ans = nums[i] + nums[j] + nums[k];

                if (dummy < target) {
                    j++;
                } else if (dummy > target) {
                    k--;
                } else {
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    j++, k--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

