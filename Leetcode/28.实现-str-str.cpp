/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-03-10-03*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 * KMP 模板题
 *
 */

// @lc code=start
class Solution {
   public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;

        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;

        vector<int> next(m + 1);

        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) j++;
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) j++;
            if (j == m) return i - m;
        }

        return -1;
    }
};
// @lc code=end
