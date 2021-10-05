/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-17-17-06*/
// ? 思路解析：
/*
 *  二分(区间具有二段性就可以使用二分)
 *
 !
 !
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        }

        cout << l << r;
        if (target >= nums[0])
            l = 0;
        else
            l = r + 1, r = nums.size() - 1;
        cout << l << r;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << r;

        return nums[r] == target ? r : -1;
    }
};
// @lc code=end
