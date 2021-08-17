/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-17-17-14*/
// ? 思路解析：
/* 
 * lc33 增加条件
 * 
 ! 
 ! 
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0]) n--;
        int l = 0, r = n;
        
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        cout << l << r << endl;


        if (target >= nums[0]) l = 0;
        else l = r + 1, r = n;

        cout << l << r << endl;


        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        cout << l << r << endl;
        return nums[r] == target;
    }
};
// @lc code=end

