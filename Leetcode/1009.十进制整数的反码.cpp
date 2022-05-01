/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2022-01-01-19-57*/

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/complement-of-base-10-integer/solution/lc1009-fengwei2002-by-kycu-ypru/

// @lc code=start
class Solution {
   public:
    int bitwiseComplement(int n) {
        int cnt = 0;
        for (int x = n; x != 0; x >>= 1) {
            cnt++;
        }

        int fixN = 1;
        for (int i = 0; i < cnt - 1; i++) {
            fixN = fixN << 1;
            fixN = fixN + 1;
        }

        return fixN - n;
    }
};
// @lc code=end
