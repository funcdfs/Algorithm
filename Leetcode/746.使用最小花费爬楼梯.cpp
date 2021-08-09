/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-09-09-47*/
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
// 版本一
class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

// @lc code=end

// 版本二
class Solution2 {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
         * DP 空间优化
         */
        int before = cost[0];
        int last = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int costI = min(before, last) + cost[i];
            before = last;  // 数据右移
            last = costI;
        }
        return min(before, last);
    }
};
