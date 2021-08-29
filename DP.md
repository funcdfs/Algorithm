## DP 分析步骤

遇到 DP 问题可以画一个图：

![DP分析框架.png](https://cdn.acwing.com/media/article/image/2021/08/11/101476_c99d7ec5f9-DP分析框架.png) 

## 斐波那契数列

- [Leetcode 509 斐波那契数列]()
- 第 n 个泰波那切数
- [Leetcode 70 爬楼梯]()
- [LeetCode 746 使用最小花费爬楼梯]()


## 数字三角形

- [数字三角形模板](/Markdown/DP_005_数字三角形.md)
- [Leetcode 62 不同路径]() 三角形转换为正方形
- [LeetCode 63 不同路径 2]() 在正方形区域添加障碍物

## 最长上升子序列应用


## 背包模板

- **01 背包**[详解](/Markdown/DP_001_01背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);`
  - `f[j] = max(f[j], f[j - v[i]] + w[i];` 逆序遍历
- **完全背包** [详解](/Markdown/DP_002_完全背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);`
  - `f[j] = max(f[j], f[j - v[i]] + w[i]);` 顺序遍历
- **多重背包** [详解](/Markdown/DP_003_多重背包.md)
  - `f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);`
  - 优化：二进制分组优化 + 01 背包
- **分组背包** [详解](/Markdown/DP_004分组背包.md)
  - `f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);`

## 背包实例应用


## 状态机 DP 

- lc 198 打家劫舍
- lc 213 打家劫舍 2
- lc 740 删除并获得点数
- lc 股票买卖 ④
- lc 股票买卖 ⑤


## 线性DP

将那些状态计算有一种模糊的递推关系的 DP 问题称为线性 DP


- [最长上升子序列](/Markdown/DP_006最长上升子序列.md)
  - [最长上升子序列 II](Markdown/DP_006最长上升子序列优化.md)
- [最长公共子序列](/Markdown/DP_007最长公共子序列.md)
- 最短编辑距离
- 编辑距离



## 区间DP

- 石子合并

## 计数类DP

AcWing 900. 整数划分
## 数位统计DP
- AcWing 338. 计数问题

- AcWing 91. 最短Hamilton路径
## 树形DP
- AcWing 285. 没有上司的舞会
## 记忆化搜索
- AcWing 901. 滑雪

