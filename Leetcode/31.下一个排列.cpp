/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-04-16-11*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! 找规律
 !
 https://leetcode.cn/problems/next-permutation/solution/lc-fengwei2002-zhao-gui-lu-by-fengwei200-w72c/
 *
 *
 */

// @lc code=start
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k--;
        if (k <= 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1]) t++;
            swap(nums[k - 1], nums[t - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
// @lc code=end
