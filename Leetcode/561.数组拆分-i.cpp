/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int arrayPairSum(vector<int>& nums) {
        //排列为有序后，每两个相邻元素为一对，总和为隔两个相加的和
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums.at(i);
        }
        return sum;
    }
};
// @lc code=end
