/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

/* tags: DP
 * 逻辑压缩：空间压缩
 *
 */

class Solution {
   public:
    int fib(int N) {  // 自底向上的方法
        if (N == 1 || N == 0) {
            return N;
        }
        int before = 0;
        int last = 1;
        for (int i = 2; i <= N; i++) {
            int cur = before;
            before = last;
            last = before + cur;
        }
        return last;
    }
};
// @lc code=end
