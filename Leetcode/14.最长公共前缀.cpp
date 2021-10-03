/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-28-08-20*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !暴力枚举方法很简单：

 先找到所有字符串的最短长度 m，然后从长度 1 到 m
 依次枚举判断是否所有字符串的前缀是否都相等。

 *
 *
 */

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) return ans;

        for (int i = 0; ; i++) {
            if (strs[0].size() <= i) return ans;
            char c = strs[0][i];

            for (auto& str : strs) {
                if (str.size() <= i || str[i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};
// @lc code=end
