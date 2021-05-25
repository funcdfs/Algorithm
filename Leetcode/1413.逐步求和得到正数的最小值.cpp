/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mini = nums.at(0);
        //因为要确保累加和始终大于等于 1 所以需要记录最低下限
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            if (sum < mini)
                mini = sum;
        }
        return mini > 0 ? 1 : abs(mini) + 1;
    }
};
// @lc code=end
