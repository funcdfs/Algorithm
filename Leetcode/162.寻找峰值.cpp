/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-17-17-38*/
// ? 思路解析：
/*
 * 不是单调性的二分例题！
 *
 !
 !
 */

// @lc code=start
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[mid - 1])
                l = mid;
            else
                r = mid - 1;
        }
        
        cout << l << r << endl;
        return r;
    }
};
// @lc code=end
