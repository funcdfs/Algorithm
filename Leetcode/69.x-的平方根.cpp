/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-52*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/sqrtx/solution/lc69-fengwei2002-fu-dian-shu-er-fen-by-k-q2ia/

/*
 ! --难点：
 ! -- 浮点数二分初始值要进行区分
 ! --  浮点数转 int 就是直接省略 小数部分，不需要使用说明函数实现
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x) {
        double l = 0, r = x;
        while (r - l > 1e-8) {
            double mid = (l + r) / 2;
            if (mid * mid >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return int(r);
    }
};
// @lc code=end
