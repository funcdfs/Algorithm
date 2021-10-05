/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-05-21-29*/

// from https://github.com/fengwei2002/Algorithm
// https://leetcode-cn.com/problems/search-insert-position/

// @lc code=start
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums.at(l) < target) l++;
        return l;
    }
};
// @lc code=end
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        if (nums[l] < target) {
            ans = l + 1;
        } else {
            ans = l;
        }

        return ans;
    }
};