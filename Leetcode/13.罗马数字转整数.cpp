/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*2021-09-30-10-18*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! 模拟 找规律
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int romanToInt(string s) {
        int n = s.length(), ans = 0;

        unordered_map<char, int> words;
        words['I'] = 1;
        words['V'] = 5;
        words['X'] = 10;
        words['L'] = 50;
        words['C'] = 100;
        words['D'] = 500;
        words['M'] = 1000;

        for (int i = 0; i < n; i++) {
            if (i != n - 1 && words[s[i + 1]] > words[s[i]]) {
                ans += words[s[i + 1]] - words[s[i]];
                i++;
            } else
                ans += words[s[i]];
        }
        return ans;
    }
};
// @lc code=end
