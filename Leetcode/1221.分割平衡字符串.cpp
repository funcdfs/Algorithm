/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
   public:
    int balancedStringSplit(string s) {
        int ans = 0, nums = 0;
        for (auto i : s) {
            ans += ((nums += (i - 'O')) == 0);
        }
        return ans;
    }
};
// @lc code=end
