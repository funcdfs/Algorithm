/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-09-09-12*/
// ? 思路解析：
/*
 *
 *
 *
 *
 ! --难点：
 ! --只有两件物品的完全背包问题，两个物品的权重相同
 ! --状态计算时为 求和
 */

// int n, m;
// int v[N], w[N];
// int f[N];

// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

//     for (int i = 1; i <= n; i++)
//         for (int j = v[i]; j <= m; j++) f[j] = max(f[j], f[j - v[i]] + w[i]);

//     cout << f[m] << endl;

//     return 0;
// }

// @lc code=start
// 版本二
class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};

// @lc code=end
