/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*2022-01-09-23-33*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/roman-to-integer/solution/lc13-fengwei2002-by-fengwei2002-dfdr/



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
