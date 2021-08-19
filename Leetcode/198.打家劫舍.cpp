/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-18-09-53*/
// ? 思路解析：
/*
 *
 *
 !
 !
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        // f[i] 代表可以在某个位置偷窃到的最高金额
        // max
        // f[i] = f[i - 1]
        //      = f[i - 2] + w[i]
        vector<int> f(nums.size() + 10, 0);
        if (nums.size() > 1) {
            f[0] = nums[0], f[1] = max(nums[1], f[0]);

            for (int i = 2; i < nums.size(); i++) {
                f[i] = max(f[i - 1], f[i - 2] + nums[i]);
            }
        } else {
            f[0] = nums[0];
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << f[i] << ' ';
        }
        int n = nums.size() - 1;
        return f[n];
    }
};
// @lc code=end
