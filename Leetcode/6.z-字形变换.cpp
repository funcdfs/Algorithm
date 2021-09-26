/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-26-10-20*/
// ? 思路解析：
/*
 *  找规律的题目

1   5   9     13
2 4 6 8 10 12 14
3   7   11    15

放入结果的
    第一个字符 index = 1
    第二个字符 index = 5
    第三个字符 index = 9
    第四个字符 index = 13
        也就是当 numRows = 3 的时候，结果优先放入 1 + (4 + n)
            当这里的 n 之后的数字不够，4 个的时候，结束


    第二行字符 index = 2
             index = 4
             index = 6
             2 4 6 8 10 12 14


1       9           17
2     8 10       16 18
3   7   11    15    19
4 6     12 14       20
5       13          21

    第二行放入，第一行下标减一的所有数字（除了第二行的第一个单独放入）
    第三行放入，第二行下标减一的所有数字 （除了第三行的第一个单独放入）
    .....
    最后一行单独判断，如果没有到最后一行，执行上面的放入操作
        到最后一行， 每两个之间的数字间隔  (numRow - 2) + 1 个数字


 !  找出第一排和最后一排的数字，
        中间填入的数字就根据第一排的数字减即可
 */

// @lc code=start
class Solution {
   public:
    string convert(string s, int n) {
        string ans;
        if (n == 1) return s;

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += 2 * n - 2) ans += s[j];
                // 考虑第一行和最后一行，第一行和第二行都是 2n - 2 的等差数列
            } else {
                for (int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size();
                    j += 2 * n - 2, k += 2 * n - 2) {
                    if (j < s.size()) ans += s[j];
                    if (k < s.size()) ans += s[k];
                }
            }
        }

        return ans;
    }
};
// @lc code=end
