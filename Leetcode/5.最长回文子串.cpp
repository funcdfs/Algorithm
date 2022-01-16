/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// date: 2022-01-07
/*
 * 枚举所有中点值，当左右索引下标都不越界，并且满足相等的条件
            就继续扩大 左右索引下标的范围，
            奇数和偶数的字符串，分别判断一次
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        string ans;
        // 如果结果回文串是奇数长度
        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && l <= r && s[l] == s[r]) {
                l--, r++;
            }
            int len = r - l + 1 - 2;
            if (ans.size() < len) {
                ans = s.substr(l + 1, len);
            }

            // 如果结果回文串是偶数长度
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && l <= r && s[l] == s[r]) {
                l--, r++;
            }
            int len = r - l + 1 - 2;
            if (ans.size() < len) {
                ans = s.substr(l + 1, len);
            }
        }

        return ans;
    }
};
// @lc code=end
