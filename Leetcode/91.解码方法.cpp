/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-22-15-35*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// 

// @lc code=start
class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n + 1);

        f[0] = 1;
        // f[i] 表示所有由前 i 个字符可以解码回去的字符串的集合
        // 属性就是 f[i] 中的元素存在几个
        // f[i] = f[i - 1] + f[i - 2]

        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') f[i] += f[i - 1];
            // 如果下一个数字在 1 - 9 之间 f[i] += f[i - 1]
            if (i > 1) {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                // 算出两个数字的 和
                if (t >= 10 && t <= 26) f[i] += f[i - 2];
                // 第二个集合合法，加到结果中
            }
        }

        return f[n];
    }
};
// @lc code=end
