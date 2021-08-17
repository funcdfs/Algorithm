/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-16-14-36*/
// ? 思路解析：
/*
 *
 * 二分查找模板题
 !
 !
 */

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

class Solution_2 {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums.at(l) < target) l++;
        return l;
    }
};