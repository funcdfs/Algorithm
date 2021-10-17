LeetCode 51-110 题


[题目链接]()  
[题解链接]()

https://github.com/fengwei2002/algorithm

### 思路

### 代码

``` cpp
// https://github.com/fengwei2002/algorithm


```

| SOLUTIONLINK |  | TAGS | STEPS |
| ------ | ---- | ---- | ------ |

| [0051](https://leetcode-cn.com/problems/n-queens/solution/lc51-fengwei2002-dfs-by-kycu-clwn/) | [51.n-皇后](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/51.n-皇后.cpp) |DFS| 典中典，用 `u - i + n` 和 `u + i` 表示对角线 dg，udg|
| [0052](https://leetcode-cn.com/problems/n-queens-ii/solution/lc52-fengwei2002-dfs-by-kycu-f4wm/) | [52.n皇后-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/52.n皇后-ii.cpp) |DFS| 同上一题，这个题不用进行 `board` 的存储，只用三个 `bool` 数组即可完成|
| [0053](https://leetcode-cn.com/problems/maximum-subarray/solution/lc53-fengwei2002-ji-chu-dp-by-kycu-zhl0/) | [53.最大子序和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/53.最大子序和.cpp) |DP| 基础 DP，`f[i] = max(f[i - 1] + nums[i], nums[i])`|
| [0054](https://leetcode-cn.com/problems/spiral-matrix/solution/lc54-fengwei2002-pian-yi-liang-shu-zu-by-0hal/) | [54.螺旋矩阵](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/54.螺旋矩阵.cpp) |模拟| 方向向量数组 dx 和 dy 的使用，使得代码极其美观|
| [0055](https://leetcode-cn.com/problems/jump-game/solution/lc55-fengwei2002-by-kycu-p3f2/) | [55.跳跃游戏](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/55.跳跃游戏.cpp) |贪心| 贪心经验题，记录每次的可以跳到的最远的位置|
| [0056](https://leetcode-cn.com/problems/merge-intervals/solution/lc56-fengwei2002-da-mo-ni-by-kycu-p81r/) | [56.合并区间](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/56.合并区间.cpp) |模拟| 典中典大模拟，按照左区间的端点对 pair 进行排序，如果下一个的左端点小于当前的右端点，那么就进行合并，否则不进行合并 |
| [0057](https://leetcode-cn.com/problems/insert-interval/solution/lc57-fengwei2002-mo-ni-by-kycu-f004/) | [57.插入区间](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/57.插入区间.cpp) | 模拟 | 前面的有序部分直接放入结果中，中间有重叠的部分合并后放入结果中，后半部分直接放入结果中 |
| [0058](https://leetcode-cn.com/problems/length-of-last-word/solution/lc58-fengwei2002wang-su-ti-by-kycu-4e6h/) | [58.最后一个单词的长度](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/58.最后一个单词的长度.cpp) |网速题| 又到了拼网速的时候了！还可以使用 stringstream 直接进行读入，每次更新腐乳单词的长度，输出最后一个长度|
| [0059](https://leetcode-cn.com/problems/spiral-matrix-ii/solution/lc59-fengwei2002pian-yi-liang-shu-zu-by-ccb44/) | [59.螺旋矩阵-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/59.螺旋矩阵-ii.cpp) |模拟| 同螺旋矩阵，使用偏移量数组|
| [0060](https://leetcode-cn.com/problems/permutation-sequence/solution/lc60-fengwei2002-ji-shu-fa-by-kycu-wpwd/) | [60.排列序列](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/60.排列序列.cpp) |计数法 hard | 考察每个位置确定之后的剩余排列的数量|
| [0061](https://leetcode-cn.com/problems/rotate-list/solution/lc61-fengwei2002-lian-biao-mo-ni-by-kycu-q859/) | [61.旋转链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/61.旋转链表.cpp) |链表， 模拟| 将链表成环之后，从链表末尾节点向后移动 add 次，重新断开环即可 |
| [0062](https://leetcode-cn.com/problems/unique-paths/solution/lc62-fengwei2002-dp-by-kycu-nw8y/) | [62.不同路径](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/62.不同路径.cpp) |DP| 经典 DP，用 `f[n][m]` 代表 路径数量， `f[n][m] = f[n - 1][m] + f[n][m - 1]`|

| [0063](https://leetcode-cn.com/problems/unique-paths-ii/solution/lc63-fengwei200-dp-by-kycu-4oc4/) | [63.不同路径-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/63.不同路径-ii.cpp) |DP| 相比于上一题，加上 `if board[i][j] == 1 continue` 即可|
| [0064](https://leetcode-cn.com/problems/minimum-path-sum/solution/lc64-fengwei2002-dp-by-kycu-1xwa/) | [64.最小路径和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/64.最小路径和.cpp) |DP| 增加权值的 不同路径|
| [0065](https://leetcode-cn.com/problems/valid-number/solution/lc65-fengwei2002-mian-xiang-yang-li-bian-krja/) | [65.有效数字](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/65.有效数字.cpp) |模拟| 没意思，pass，面向样例编程|


| [0066](https://leetcode-cn.com/problems/plus-one/solution/lc66-fengwei2002-gao-jing-du-jia-fa-by-k-g03q/) | [66.加一](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/66.加一.cpp) | 高精度加法| 高精度加法模板题，利用两次翻转可以使代码更加美观|
| [0067](https://leetcode-cn.com/problems/add-binary/solution/lc67-fengwei2002-mo-ni-by-kycu-y3mu/) | [67.二进制求和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/67.二进制求和.cpp) | 高精度加法 | 高精度加法模板题++|
| 0068 | [68.文本左右对齐](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/68.文本左右对齐.cpp) |模拟| 大模拟|


| [0069](https://leetcode-cn.com/problems/sqrtx/solution/lc69-fengwei2002-fu-dian-shu-er-fen-by-k-q2ia/) | [69.x-的平方根](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/69.x-的平方根.cpp) |二分| 浮点数二分典中典|
| [0070](https://leetcode-cn.com/problems/climbing-stairs/solution/lc70-fengwei2002-dp-by-kycu-kfe0/) | [70.爬楼梯](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/70.爬楼梯.cpp) | DP | 简单 DP： `f[i] = f[i - 1] + f[i - 2]`|


| 0071 | [name03](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name03.cpp) |tags| Content|


