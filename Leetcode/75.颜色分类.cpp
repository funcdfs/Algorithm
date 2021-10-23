/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-23-21-40*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link: 三指针
// https://leetcode-cn.com/problems/sort-colors/solution/lc75-fengwei2002-by-kycu-3ivm/

// @lc code=start
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if (nums[i] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[k--]);
            else
                i++;
        }
    }
};
// @lc code=end