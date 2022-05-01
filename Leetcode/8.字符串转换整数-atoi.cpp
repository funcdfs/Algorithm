/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2022-01-09-22-51*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/string-to-integer-atoi/solution/lc8-fengwei2002-by-fengwei2002-sg6u/

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        // 丢弃前面所有的空格
        while (index < s.size() && s[index] == ' ') index++;
        if (index == s.size()) return 0;
        

        // 检查是正号还是负号
        int minus = 1;
        if (s[index] == '-') {
            minus = -1;
            index++;
        } else if (s[index] == '+') {
            index++;
        }

        int ans = 0;
        while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
            int x = s[index] - '0';

            // 判断是否越界
            if (ans > (INT_MAX - x) / 10) {
                if (minus > 0) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            
            ans = ans * 10 + x;
            index++;
            if (ans > INT_MAX) break;
        }

        ans *= minus;

        return ans;
    }
};

// @lc code=end
