/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-27-17-42*/
// ? 思路解析：
/*
 * oddSum 排除 "ccc"
 * 
 *
 *
 ! --难点：
 ! -- x 所有的双数，加上一个最大的单数就是答案
 ! -- y 所有的双数，加上所有单数减一（变为双数），加上只出现一次的元素
 */

// @lc code=start
class Solution {
   public:
    int longestPalindrome(string s) {
        int ans = 0;

        int lowerCaseCount[26];
        int upperCaseCount[26];
        memset(lowerCaseCount, 0, sizeof lowerCaseCount);
        memset(upperCaseCount, 0, sizeof upperCaseCount);

        for (auto i : s) {
            if (i <= 'z' && i >= 'a') {
                lowerCaseCount[i - 'a']++;
            }
            if (i <= 'Z' && i >= 'A') {
                upperCaseCount[i - 'A']++;
            }
        }

        bool flag = false;
        int oddSum = 0;
        for (int i = 0; i < 26; i++) {
            if (lowerCaseCount[i] % 2 != 0)
                ans += lowerCaseCount[i] - 1, oddSum++;
            if (upperCaseCount[i] % 2 != 0)
                ans += upperCaseCount[i] - 1, oddSum++;
            if (oddSum == 1 || upperCaseCount[i] == 1 || lowerCaseCount[i] == 1)
                flag = true;

            if (lowerCaseCount[i] % 2 == 0) ans += lowerCaseCount[i];
            if (upperCaseCount[i] % 2 == 0) ans += upperCaseCount[i];
        }
        if (flag) ans += 1;
        return ans;
    }
};
// @lc code=end
