/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-13-19-16*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/maximum-subarray/solution/lc53-fengwei2002-ji-chu-dp-by-kycu-zhl0/

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int f[n];
        memset(f, -1e9, sizeof f);

        if (n == 1) {
            return nums[0];
        } else {
            f[0] = nums[0];
            f[1] = max(f[0] + nums[1], nums[1]);
            if (n == 2) {
                return max(f[0], f[1]);
            } else {
                for (int i = 1; i < n; i++) {
                    f[i] = max(f[i - 1] + nums[i], nums[i]);
                }
            }
        }

        int ans = -1e9;
        for (int i = 0; i < n; i++) ans = max(ans, f[i]);

        return ans;
    }
};

class Solution2 {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;

        for (int i = 0, last = 0; i < nums.size(); i++) {
            last = nums[i] + max(last, 0);
            ans = max(ans, last);
        }
        
        return ans;
    }
};
// @lc code=end
