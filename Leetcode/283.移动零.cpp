/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-08-18-30*/
// ? 思路解析：
/* 
 * 
 * 
 ! 
 ! 
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) nums[k++] = nums[i];
        }
        for (int i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

