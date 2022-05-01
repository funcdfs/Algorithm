/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-06*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/merge-sorted-array/solution/lc88-fengwei2002-by-kycu-rejy/

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m - 1;
        int i = m - 1, j = n - 1;
        // 避免没有被用过的数字被覆盖，从后往前，依次放入最大值
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
        // nums1 不用扫尾
    }
};
// @lc code=end
