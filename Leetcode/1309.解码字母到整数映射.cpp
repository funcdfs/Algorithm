/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 */

// @lc code=start

#include <iostream>
using namespace std;

class Solution {
   public:
    string freqAlphabets(string s) {
        int len = s.length();
        string ans = "";
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '#') {
                int val = 10 * (s[i - 2] - '0') + (s[i - 1] - '0') - 1;
                ans += ('a' + val);
                i -= 2;
            } else {
                ans += ('a' + s[i] - '1');
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
