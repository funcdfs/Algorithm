/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-26-20-30*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 * 题解： https://leetcode-cn.com/problems/string-to-integer-atoi/solution/lc8-fengwei2002-by-fengwei2002-sg6u/
 *
 */

// @lc code=start
class Solution {
   public:
    int myAtoi(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k++;
        if (k == str.size()) return 0;

        int minus = 1;
        if (str[k] == '-')
            minus = -1, k++;
        else if (str[k] == '+')
            k++;

        int ans = 0;
        while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
            int x = str[k] - '0';

            if (minus > 0 && ans > (INT_MAX - x) / 10) return INT_MAX;
            if (minus < 0 && -ans < (INT_MIN + x) / 10) return INT_MIN;
            if (-ans * 10 - x == INT_MIN) return INT_MIN;
            if (ans > INT_MAX) break;

            ans = ans * 10 + x;
            k++;
        }
        ans *= minus;

        return ans;
    }
};
// @lc code=end
