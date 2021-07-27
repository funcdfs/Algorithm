/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-27-16-33*/
// ? 思路解析：
/*
 *
 * 高精度加法类似，注意使用 sum 的时候 是 sum + '0'
 *
 *
 ! --难点：
 ! -- 当计算 9999 + 9999 的时候会产生溢出，所以不能在元空间上进行操作
 ! -- 加法的计算步骤
 */
// @lc code=start
class Solution {
   public:
    string addStrings(string num1, string num2) {
        string str;
        int cur = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || cur != 0) {
            if (i >= 0) cur += num1[i--] - '0';
            if (j >= 0) cur += num2[j--] - '0';
            // printf("cur == %d\n", cur);
            str.push_back(char(cur % 10 + '0'));
            cur /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
// @lc code=end
