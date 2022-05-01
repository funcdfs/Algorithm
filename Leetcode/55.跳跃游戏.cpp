/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-45*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/jump-game/solution/lc55-fengwei2002-by-kycu-p3f2/

// @lc code=start

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, k = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);  // 记录每次的可以跳到的最远的位置
        }
        return true;
    }
};

// @lc code=end
