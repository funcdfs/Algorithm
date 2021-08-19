> 【动态规划】：指那些看上去很懵逼但存在几行 for 循环就可以实现最优解的题目

## DP 分析步骤

遇到 DP 问题可以画一个图：

![DP分析框架.png](https://cdn.acwing.com/media/article/image/2021/08/11/101476_c99d7ec5f9-DP分析框架.png) 

## 基础题目

这些基础题目可以了解 DP 解决的大概问题类型轮廓

- `Easy_1` [Leetcode 509 斐波那契数列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0509.%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0.md)
  - 要对 1, 2, 3, 5, 8 数据敏感
  - Leetcode 1137 泰波那契数列 三个数字的斐波那契数列

- `Easy_2` [Leetcode 70 爬楼梯](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.md)
  - （斐波那契数列）（完全背包）（快速幂）
  - dp[i] 构造：（按照题意不存在 dp[0]）  
    首先是 dp[i - 1]，上 i-1 层楼梯，有 dp[i - 1] 种方法，那么再用一步跳一个台阶就是 dp[i] 了。  
    还有就是 dp[i - 2]，上 i-2 层楼梯，有 dp[i - 2] 种方法，那么再用一步跳两个台阶就是 dp[i] 了。  
  - `dp[i] = dp[i - 1] + dp[i - 2]`
- `Easy_3` [LeetCode 746 使用最小花费爬楼梯](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.md)
  - 数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i](下标从 0 开始)。
    每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
    请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
  - `dp[i] = min(dp[i - 1], dp[i -2]) + cost[i];`
- `Medium_1`[Leetcode 62 不同路径](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.md)
  - （动态规划，数字三角形，记忆化搜索，数论）
  - `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`
  - `Medium_2` [LeetCode 63 不同路径 2](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.md)，添加障碍物
  - ``` cpp
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    } // 有障碍物的路径 dp 数组记录距离为 0， 不是障碍物的时候才进行计算 
    ```

## 数字三角形



## 背包九讲 4/9

- **01 背包**[详解](/Markdown/DP_001_01背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);`
  - `f[j] = max(f[j], f[j - v[i]] + w[i];` 逆序遍历
- **完全背包** [详解](/Markdown/DP_002_完全背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);`
  - `f[j] = max(f[j], f[j - v[i]] + w[i]);` 顺序遍历
- **多重背包** [详解](/Markdown/DP_003_多重背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);`
  - 二进制分组优化 + 01 背包
- **分组背包** [详解](/Markdown/DP_004分组背包.md)
  - `f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);`

## 线性DP

将那些状态计算有一种模糊的递推关系的 DP 问题称为线性 DP

```diff
+ test
- test 
! test 
# test
```

- [数字三角形](/Markdown/DP_005_数字三角形.md)
- [最长上升子序列](/Markdown/DP_006最长上升子序列.md)
  - [最长上升子序列 II](Markdown/DP_006最长上升子序列优化.md)
- [最长公共子序列](/Markdown/DP_007最长公共子序列.md)
- 最短编辑距离
- 编辑距离
## 区间DP
- AcWing 282. 石子合并
## 计数类DP
AcWing 900. 整数划分
## 数位统计DP
- AcWing 338. 计数问题
## 状态压缩DP
- AcWing 291. 蒙德里安的梦想
- AcWing 91. 最短Hamilton路径
## 树形DP
- AcWing 285. 没有上司的舞会
## 记忆化搜索
- AcWing 901. 滑雪

