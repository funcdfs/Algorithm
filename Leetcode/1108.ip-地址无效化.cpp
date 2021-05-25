/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
#include <iostream>

using namespace std;
class Solution {
   public:
    string defangIPaddr(string address) {
        string res("1");
        res.clear();
        for (int i = 0; i < address.length(); i++) {
            if (address.at(i) != '.') {
                res.push_back(address.at(i));
            } else {
                res += "[.]";
            }
        }
        return res;
    }
};
// @lc code=end
