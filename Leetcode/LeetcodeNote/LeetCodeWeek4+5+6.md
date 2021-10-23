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
| [0071](https://leetcode-cn.com/problems/simplify-path/solution/lc71-fengwei2002-by-kycu-z3ke/) | [71.简化路径](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/71.简化路径.cpp) | 栈模拟| 用两个字符串模拟栈的操作，遇到 `.` 不作为，遇到 `..` 弹出上一段路径，否则就正常加入结果路径|
| [0072](https://leetcode-cn.com/problems/edit-distance/solution/lc72-fengwei2002-jing-dian-dp-by-kycu-g3oe/) | [72.编辑距离](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/72.编辑距离.cpp) | DP | 经典 DP 问题，将 `f[i][j]` 分为四种情况，取最小值, `f[i, j] = f[i - 1][j - 1] + 1 || f[i, j] = f[i - 1][j - 1]` , `f[i, j] = f[i - 1, j] + 1`, `f[i , j] = f[i, j - 1] + 1`|
| [0073](https://leetcode-cn.com/problems/set-matrix-zeroes/solution/lc73-fengwei2002-by-kycu-z34l/) | [73.矩阵置零](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/73.矩阵置零.cpp) |模拟 矩阵| 背过，基本不可能自己想出来。用两个变量记录第一行和第一列是否有 0，遍历整个矩阵，用矩阵的第一行和第一列记录对应的行和列是否有 0。把含有 0 的行和列都置成 0。|
| [0074](https://leetcode-cn.com/problems/search-a-2d-matrix/solution/lc74-fengwei2002-er-fen-by-kycu-0llk/) | [74.搜索二维矩阵](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/74.搜索二维矩阵.cpp) |模拟 矩阵| 注意一个值对于矩阵映射之后的，行和列对应的下标|
| [0075](https://leetcode-cn.com/problems/sort-colors/solution/lc75-fengwei2002-by-kycu-3ivm/) | [75.颜色分类](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/75.颜色分类.cpp) |三指针 快速排序| 用 j i k 代表 0 1 2 的下标，i < k 的时候进行原地的数组交换，或者将 vector 转换为 数组，直接背快排模板|
| [0076](https://leetcode-cn.com/problems/minimum-window-substring/solution/lc76-fengwei2002-by-kycu-o6ua/) | [76.最小覆盖子串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/76.最小覆盖子串.cpp) | 滑动窗口 **hard**| 思想同第 30 题，TODO |
| [0077](https://leetcode-cn.com/problems/combinations/solution/lc77-fengwei2002-dfs-by-kycu-onsw/) | [77.组合](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/77.组合.cpp) | DFS | DFS 典中典，注意仔细考虑向下一次迭的参数具体传值 |
| [0078](https://leetcode-cn.com/problems/subsets/solution/lc78-fengwei2002-by-kycu-qc7s/) | [78.子集](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/78.子集.cpp) | DFS | dfs谁都会，但是这个可以用二进制的迭代写法，很经典|
| [0079](https://leetcode-cn.com/problems/word-search/solution/lc79-fengwei2002-pian-yi-liang-shu-zu-df-a10y/) | [79.单词搜索](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/79.单词搜索.cpp) | DFS | 这是一个利用矩阵偏移量数组的 DFS，对于矩阵中的每一个下标，每次向下迭代搜索三个方向，如果搜到了` word.size() - 1, ` 就 `return true`|
| [0080](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/lc80-fengwei2002-by-kycu-gl1v/) | [80.删除有序数组中的重复项-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/80.删除有序数组中的重复项-ii.cpp) | 链表 模拟| 定义一个指针 k，表示新数组的末尾，然后从前往后扫描原数组，如果数组中的数字 `k > 2 || nums[k - 1] || nums[k - 2]`，`nums[k++] = i`|
| [0081](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/lc81-fengwei2002-by-kycu-p67z/) | [81.搜索旋转排序数组-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/81.搜索旋转排序数组-ii.cpp) |tags| Content|
| [0082](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/lc82-fengwei2002-by-kycu-uhzd/) | [82.删除排序链表中的重复元素-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/82.删除排序链表中的重复元素-ii.cpp) |tags| Content|
| [0083](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/solution/lc83-fengwei2002-by-kycu-0n25/) | [83.删除排序链表中的重复元素](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/83.删除排序链表中的重复元素.cpp) |tags| Content|
| [0084](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/lc84-fengwei2002-by-kycu-33ky/) | [84.柱状图中最大的矩形](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/84.柱状图中最大的矩形.cpp) |tags| Content|
| [0085](https://leetcode-cn.com/problems/maximal-rectangle/solution/lc85-fengwei2002-by-kycu-fr0x/) | [85.最大矩形](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/85.最大矩形.cpp) |tags| Content|
| [0086](https://leetcode-cn.com/problems/partition-list/solution/lc86-fengwei2002-by-kycu-4kri/) | [86.分隔链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/86.分隔链表.cpp) |tags| Content|
| [0087](https://leetcode-cn.com/problems/scramble-string/solution/lc87-fengwei2002-by-kycu-obql/) | [87.扰乱字符串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/87.扰乱字符串.cpp) |tags| Content|
| [0088](https://leetcode-cn.com/problems/merge-sorted-array/solution/lc88-fengwei2002-by-kycu-rejy/) | [88.合并两个有序数组](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/88.合并两个有序数组.cpp) |tags| Content|
| [0089](https://leetcode-cn.com/problems/gray-code/solution/lc89-fengwei2002-by-kycu-rjei/) | [89.格雷编码](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/89.格雷编码.cpp) |tags| Content|
| [0090](https://leetcode-cn.com/problems/subsets-ii/solution/lc90-fengwei2002-by-kycu-jkwn/) | [90.子集-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/90.子集-ii.cpp) |tags| Content|
| [0091](https://leetcode-cn.com/problems/decode-ways/solution/lc91-fengwei2002-by-kycu-1yv7/) | [91.解码方法](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/91.解码方法.cpp) |tags| Content|
| [0092](https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/lc92-fengwei2002-by-kycu-f9si/) | [92.反转链表-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/92.反转链表-ii.cpp) |tags| Content|
| [0093](https://leetcode-cn.com/problems/restore-ip-addresses/solution/lc93-fengwei2002-by-kycu-ptu7/) | [93.复原-ip-地址](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/93.复原-ip-地址.cpp) |tags| Content|
| [0094](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/lc94-fengwei2002-by-kycu-9iye/) | [94.二叉树的中序遍历](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/94.二叉树的中序遍历.cpp) |tags| Content|
| [0095](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/lc95-fengwei2002-by-kycu-lrga/) | [95.不同的二叉搜索树-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/95.不同的二叉搜索树-ii.cpp) |tags| Content|
| [0096](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/lc96-fengwei2002-by-kycu-lekx/) | [96.不同的二叉搜索树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/96.不同的二叉搜索树.cpp) |tags| Content|
| [0097](https://leetcode-cn.com/problems/interleaving-string/solution/lc97-fengwei2002-by-kycu-y68b/) | [97.交错字符串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/97.交错字符串.cpp) |tags| Content|
| [0098](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/lc98-fengwei2002-by-kycu-8dl4/) | [98.验证二叉搜索树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/98.验证二叉搜索树.cpp) |tags| Content|
| [0099](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/lc99-fengwei2002-by-kycu-45z2/) | [99.恢复二叉搜索树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/99.恢复二叉搜索树.cpp) |tags| Content|
| [0100](https://leetcode-cn.com/problems/same-tree/solution/lc100-fengwei2002-by-kycu-2pce/) | [100.相同的树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/100.相同的树.cpp) |tags| Content|
| 0101 | [101.对称二叉树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/101.对称二叉树.cpp) |tags| Content|
| 0102 | [102.二叉树的层序遍历](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/102.二叉树的层序遍历.cpp) |tags| Content|
| 0103 | [103.二叉树的锯齿形层序遍历](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/103.二叉树的锯齿形层序遍历.cpp) |tags| Content|
| 0104 | [104.二叉树的最大深度](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/104.二叉树的最大深度.cpp) |tags| Content|
| 0105 | [105.从前序与中序遍历序列构造二叉树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/105.从前序与中序遍历序列构造二叉树.cpp) |tags| Content|
| 0106 | [106.从中序与后序遍历序列构造二叉树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/106.从中序与后序遍历序列构造二叉树.cpp) |tags| Content|
| 0107 | [107.二叉树的层序遍历-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/107.二叉树的层序遍历-ii.cpp) |tags| Content|
| 0108 | [108.将有序数组转换为二叉搜索树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/108.将有序数组转换为二叉搜索树.cpp) |tags| Content|
| 0109 | [109.有序链表转换二叉搜索树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/109.有序链表转换二叉搜索树.cpp) |tags| Content|
| 0110 | [110.平衡二叉树](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/110.平衡二叉树.cpp) |tags| Content|
