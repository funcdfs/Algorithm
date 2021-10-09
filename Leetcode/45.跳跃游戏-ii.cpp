/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-22-49*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        int end = 0;
        int step = 0;

        for (int i = 0; i < n - 1; i++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};
// @lc code=end
