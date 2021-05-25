/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int fib(int N) {  // 自底向上的方法
        if (N == 1 || N == 0) {
            return N;
        }
        int dp0 = 0;
        int dp1 = 1;
        for (int i = 2; i <= N; i++) {
            int cur = dp0;
            dp0 = dp1;
            dp1 = dp0 + cur;
        }
        return dp1;
    }
};
// @lc code=end
