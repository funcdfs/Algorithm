/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-20-23-08*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solution/lc80-fengwei2002-by-kycu-gl1v/

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto x : nums) {
            if (k < 2 || nums[k - 1] != x || nums[k - 2] != x) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
// @lc code=end
