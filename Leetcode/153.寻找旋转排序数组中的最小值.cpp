/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-17-17-28*/
// ? 思路解析：
/* 
 * 
 * lc 33 相同
 ! 
 ! 
 */


// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 相当于 target = nums[0]
        // 先寻找边界值
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        int ans = 0;
        cout << l << r << endl;

        if (r < nums.size() - 1) {
            ans = min(nums[l], nums[r + 1]);
        } else {
            ans = nums[0];
        }
        // 比较前半段元素和后半段元素哪个最小值更小一点
        return ans;
    }
};
// @lc code=end

