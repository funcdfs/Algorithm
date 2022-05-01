/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-17-16-49*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/add-binary/solution/lc67-fengwei2002-mo-ni-by-kycu-y3mu/

// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string c;
        for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            c += to_string(t % 2);
            t /= 2;
        }

        reverse(c.begin(), c.end());
        return c;
    }
};

// @lc code=end
