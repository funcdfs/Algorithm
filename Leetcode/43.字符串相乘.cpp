/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-20-13*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! https://leetcode-cn.com/problems/multiply-strings/solution/lc43-fengwei2002-gao-jing-du-cheng-fa-by-nd65/
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');
        for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');
        // A, B 逆序放入

        vector<int> C(n + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                C[i + j] += A[i] * B[j];
            }
        }

        for (int i = 0, t = 0; i < C.size(); i++) {
            t += C[i]; // 进位加上本来的数字
            C[i] = t % 10; // 最后的值是 模十
            t /= 10; // 进位
        }

        int k = C.size() - 1;
        while (k > 0 && C[k] == 0) k--;
        string ans = "";
        for (int i = k; i >= 0 ;i--) {
            ans += C[i] + '0';
        }

        return ans;
    }
};
// @lc code=end
