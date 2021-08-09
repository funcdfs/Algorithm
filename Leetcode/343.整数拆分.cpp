/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-09-15-05*/
// ? 思路解析：
/* 
 * 
 * 
 * 
 * 
 ! --难点：
 ! --
 ! --
 */



// @lc code=start
class Solution {
   public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

// @lc code=end

