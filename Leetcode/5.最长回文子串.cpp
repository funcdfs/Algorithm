/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-22-14-42*/
// ? 思路解析：
/*
 * 枚举所有中点值，当左右索引下标都不越界，并且满足相等的条件
            就继续扩大 左右索引下标的范围，
            奇数和偶数的字符串，分别判断一次
 *
 !  找出最长的连续回文子串
 !
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        string ans;

        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;
            while (l <= r && l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if (ans.size() < r - l - 1) ans = s.substr(l + 1, r - l - 1);

            l = i, r = i + 1;
            while (l <= r && l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if (ans.size() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
        }

        return ans;
    }
};
// @lc code=end
