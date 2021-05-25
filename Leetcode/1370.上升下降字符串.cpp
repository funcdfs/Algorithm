/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution {
   public:
    int h[26];

    inline bool haveChar() {
        for (int i = 0; i < 26; ++i) {
            if (h[i]) {
                return true;
            }
        }
        return false;
    }  //力扣中使用自定义函数的方法，全局中声明

    string sortString(string s) {
        for (const auto& c : s)
            ++h[c - 'a'];
        string ret;
        auto appendChar = [&](int p) {
            if (h[p]) {
                --h[p];
                ret.push_back(p + 'a');
            }
        };
        while (true) {
            if (!haveChar())
                break;
            for (int i = 0; i < 26; ++i)
                appendChar(i);
            for (int i = 25; i >= 0; --i)
                appendChar(i);
        }
        return ret;
    }
};
// @lc code=end