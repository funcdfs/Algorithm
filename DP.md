> 【动态规划】：指那些看上去很懵逼但存在几行 for 循环就可以实现最优解的题目

**以下收录的题目都给出了题解链接**

## 步骤

| 进度 | 步骤                       | 详细描述                                               |
| ---- | -------------------------- | ------------------------------------------------------ |
| 30 % | 确定 dp 数组以及下标的含义 | 一般 dp 数组的最后一位就是题目结果                     |
| 60 % | 确定递推公式               |                                                        |
| 70 % | dp 数组如何初始化          | (dp[0], dp[1] 之类的初始数据是多少），可能不存在 dp[0] |
| 95 % | 确定遍历顺序               | （从前往后还是从后往前，从下标几开始）                 |
| 100% | 举例推导 dp 数组           | （举例测试状态转移公式，打印 dp 数组）                 |

## 基础题目

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
- `Medium_2` [LeetCode 343 整数拆分](../Algorithm/Markdown/0343.整数拆分.md)
  - （动态规划，贪心）
  - 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
  - `dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));` 取两种渠道中的最大值


## 背包九讲

面试：01 背包，完全背包，多重背包， 分组背包

- 01 背包
  - 