/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-18-12-56*/
// ? 思路解析：
/*
 * 状态机类型 DP 很巧妙
 */

// @lc code=start
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 10010;
        int m = 0;

        vector<int> tot(N, 0);  // 定义计数数组
        for (int x : nums) {
            tot[x]++;
            m = max(m, x);  // m 代表最大值
        }

        vector<vector<int>> f(m + 1, vector<int>(2));
        // 开辟二维数组
        // f[i][0] 代表不选第 i 个元素的值
        // f[i][1] 代表选第 i 个元素的值
        /* f[i][0] 的来源有两种
        1. f[i - 1][1]
        2. f[i - 1][0]
        f[i][1] 的来源只有一种
        1. f[i - 2] + w[i]; (w[i] = 当前值 * 出现的次数)
        */
        f[0][0] = 0;
        f[0][1] = INT_MIN; 
        // 为了确保 f[1][0] = max f[0][0], f[0][1] 
        //         f[1][1] = f[0][0] + w[1] 正确，
        // 所以要初始化 f[0][0] = 0; f[0][1] = INT_MIN;
        // 其实不是 负无穷也可以，只要是一个比 0 小的数字就可以实现相同的目的 例如 -1

        // 然后从 1 开始，遍历到序列中的最大值 m 
        for (int i = 1; i <= m; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + tot[i] * i;
        }
        // 返回选或者 不选，最后一个值，中最大的那一个
        return max(f[m][0], f[m][1]);
    }
};
// @lc code=end
