/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-23-21-50*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/solution/lc81-fengwei2002-by-kycu-p67z/

// @lc code=start
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0]) n--;
        int l = 0, r = n;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        } // 去除前导零之后找到 两段的边界位置

        if (target >= nums[0])
            l = 0;
        else
            l = r + 1, r = n;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r] == target;
    }
};
// @lc code=end
