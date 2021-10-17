/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-17-17-33*/

// depository: 
// https://github.com/fengwei2002/Algorithm
// solution link: 
// 

// @lc code=start
class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};

// @lc code=end
