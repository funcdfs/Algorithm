/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
   public:
    string toLowerCase(string str) {
        int a = 'a' - 'A';
        for (int i = 0; i < str.size(); i++) {
            if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
                str.at(i) += a;
            }
        }
        return str;
    }
};
// @lc code=end
