/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-18-12-56*/
// ? 思路解析：
/* 
 *  虽然是 DP 题目，但我想用滑动窗口的最大值试一下
 * 
 ! 
 ! 
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0;
        vector<int> l(nums.size() + 10, 0);
        for (int i = 0; i < nums.size(); i++) {
            l[nums[i]]++;
        }
        if (nums.size() >= 3) {
            vector<int> q;
        }
        return ans;
    }
};
// @lc code=end

