/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// date: 2021-08-17
// ? 思路解析：题目描述不太行

// @lc code=start
// 版本一
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 0 1 2 3 4 5 ... i - 1, i, 0;
        int n = cost.size();
        // f[i] 代表到达 i 阶时的花费数
        // min 最低花费
        // f[n] = f[n - 1] + cost[n]  
        //      = f[n - 2] + cost[n];
        vector<int> f(n + 10, 0);
        f[0] = cost[0], f[1] = cost[1]; 
        // 你可以从下标为 0 或者 下标为 1 作为初始阶梯
        for (int i = 2; i < n; i++) {
            f[i] = min(f[i - 1] + cost[i], f[i - 2] + cost[i]);
        }
        return min(f[n - 2], f[n - 1]);
        //楼顶 0 的来源是，n - 1 和 n - 2 的最小值
    }
};

// @lc code=end

// 版本二
class Solution2 {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
         * DP 空间优化
         */
        int before = cost[0];
        int last = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int costI = min(before, last) + cost[i];
            before = last;  // 数据右移
            last = costI;
        }
        return min(before, last);
    }
};
