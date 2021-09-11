/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-08-16-47*/
// ? 思路解析：
/* 
 *  二分查找模板题
 * 
 ! 
 ! 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = 0;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        } 

        if (nums[l] == target) ans = l;
        else ans = -1;
        
        return ans;
    }
};
// @lc code=end

