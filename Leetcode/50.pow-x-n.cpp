/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-23-25*/

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
    double myPow(double x, int n) {
        typedef long long LL;
        bool is_minus = n < 0;

        double ans = 1;
        for (LL k = abs(LL(n)); k; k >>= 1) {
            if (k & 1) ans *= x;
            x *= x;
        }
        if (is_minus) ans = 1 / res;
        return ans;
    }
};
// @lc code=end
