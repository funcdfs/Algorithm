/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        //直接改变传入数组的数据来节省空间
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums.at(i);
            nums.at(i) = sum;
        }
        return nums;
    }
};
// @lc code=end
