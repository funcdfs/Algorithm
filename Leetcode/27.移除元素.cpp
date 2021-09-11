/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-08-18-18*/
// ? 思路解析： 值保留值不等于 val 的元素

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;

        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};
// @lc code=end

