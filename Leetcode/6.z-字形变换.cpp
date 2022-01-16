/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* date: 2022-01-07
 *  找规律的题目

1        9          17
2     8 10       16 18
3   7   11    15    19
4 6     12 14       20
5       13          21

第一行是一个等差数列，公差为 2n - 2，
    因为第一行的第一个数字和第二个数字中间相隔了 2n - 2 个其他的数字

考虑第二行：
    第二行可以变为两个等差数列进行考虑， 每一个单独的等差数列的公差都是 2n - 2

只有第一行和最后一行是单独的等差数列，其他位置都是两个等差数列交织形成的

 */

// @lc code=start
class Solution {
   public:
    string convert(string s, int n) {
        string ans = s;
        if (n == 1) return ans;

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == (n - 1)) {
                // 第一行和最后一行
                for (int j = i; j < s.size(); j += 2 * n - 2) {
                    ans += s[j];
                }
            } else {
                // 其他行，分成两个部分，列上的，斜线上的
                // k 是 i 的下一个位置向前移动 i 个的位置
                for (int j = i, k = 2 * n - 2 - i;
                     j < s.size() || k < s.size();
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
