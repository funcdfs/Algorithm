/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //目的是将数组的顺序打乱，按照2n来重新排列
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            result.push_back(nums.at(i - 1));
            result.push_back(nums.at(n + i - 1));
        }
        return result;
    }
};
// @lc code=end
