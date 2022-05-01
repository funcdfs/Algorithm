/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-06-17-27*/

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/valid-palindrome/solution/lc125-fengwei2002-by-kycu-j760/

// @lc code=start
class Solution {
   public:
    bool check(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||
               c >= '0' && c <= '9';
    }
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !check(s[i])) i++;
            while (i < j && !check(s[j])) j--;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
// @lc code=end
