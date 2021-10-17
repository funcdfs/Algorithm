/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-16-20*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link: 没意思，。pass
// https://leetcode-cn.com/problems/valid-number/solution/lc65-fengwei2002-mian-xiang-yang-li-bian-krja/

// @lc code=start
class Solution {
   public:
    bool isNumber(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l++;
        while (l <= r && s[r] == ' ') r--;
        if (l > r) return false;
        s = s.substr(l, r - l + 1);
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if (s.empty()) return false;

        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E'))
            return false;

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (dot > 0 || e > 0) return false;
                dot++;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i || i + 1 == s.size() || e > 0) return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) return false;
                    i++;
                }
                e++;
            } else if (s[i] < '0' || s[i] > '9')
                return false;
        }

        return true;
    }
};
// @lc code=end
