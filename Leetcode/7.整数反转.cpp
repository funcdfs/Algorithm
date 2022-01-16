/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-26-20-17*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 
 10*r + x % 10 > int_max
 10 r > max - x % 10
 r > (max - x % 10) / 10

 *
 */

// @lc code=start
class Solution {
   public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > 0 && r > (INT_MAX - x % 10) / 10) return 0;
            if (r < 0 && r < (INT_MIN - x % 10) / 10) return 0;
            r = r * 10 + x % 10; // 主要判断这一行什么时候溢出
            x /= 10;
        }
        return r;
    }
};
// @lc code=end