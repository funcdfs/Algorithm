/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-03-10-39*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! 不使用乘法，除法 mod 运算，执行两个数字的除法
 !
 *
 *  倍增做减法
 *
 * 快速幂
 *
 * 把 商 k 用 二进制进行表示
 * k 只有log 项
 * 那么 x 可以写为 x = 2^1 * y - 2^4 * y - 2^5 * y;
 * 可以将 2^31 项，缩减为 31 项，
 * 使减法的 复杂度大大降低
 *
 * 预处理 2^(0..31) * y 的值 共 31 项
 *
 *  如果 x/y > 2^30 次方，那么它的二进制表示 2^30 次方的位置就是 1
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int divide(int x, int y) {
        typedef long long LL;
        vector<LL> exp;

        bool isMinus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) isMinus = true;

        LL a = abs((LL)x), b = abs((LL)y);
        for (LL i = b; i <= a; i = i + i) exp.push_back(i);

        LL ans = 0;
        for (int i = exp.size() - 1; i >= 0; i--)
            if (a >= exp[i]) {
                a -= exp[i];
                ans += 1ll << i;
            }

        if (isMinus) ans = -ans;

        if (ans > INT_MAX || ans < INT_MIN) ans = INT_MAX;

        return ans;
    }
};
// @lc code=end
