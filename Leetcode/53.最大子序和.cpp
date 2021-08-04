/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-04-15-31*/
// ? 思路解析：
/* 
 * 
 * 
 * 
 * 
 ! --难点：
 ! --
 ! -- TODO： 动态规划
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, last = 0; i < nums.size(); i++) {
            last = nums[i] + max(last, 0);
            res = max(res, last);
        }
        return res;
    }
};
// @lc code=end

