/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-16-12-10*/
// ? 思路解析：
/* 
 * 二分模板的应用
 * 
 ! --难点： 边界情况的仔细判断
 */


// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int k = target;
        if (n == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (nums[l] == k) {
            ans.push_back(l);
            l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums[mid] <= k) l = mid;
                else r = mid - 1;
            }
            ans.push_back(l);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
// @lc code=end

