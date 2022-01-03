- 111 - 155
- 160、162、164 ~ 169、171 ~ 174、179、187、188

| SOLUTIONLINK | Code | TAGS | STEPS |
| ------ | ---- | ---- | ------ |
| [0111](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/lc111-fengwei2002-by-kycu-y68q/) | [111.二叉树的最小深度](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/111.二叉树的最小深度.go) | 二叉树 | 只有当这个树枝的左右树枝都是空的时候，才能算是深度的结束位置|
| [0112](https://leetcode-cn.com/problems/path-sum/solution/lc112-fengwei2002-by-kycu-gurg/) | [112.路径总和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/112.路径总和.go) | DFS | 树上搜索，`targetSum` 每次减去 `root.Val` 即可|
| [0113](https://leetcode-cn.com/problems/path-sum-ii/solution/lc113-fengwei2002-guan-yu-bu-li-jie-slic-hank/) | [113.路径总和-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/113.路径总和-ii.go) | DFS | 和上一题相同，当 targetSum 减到 0 的时候，把 path 放入 ans 中，由于 golang 中的切片是对数组的视图，所以放入 ans 的时候需要使用 copy 函数复制一份|
| [0114](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/lc114-fengwei2002-by-kycu-13h6/) | [114.二叉树展开为链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/114.二叉树展开为链表.go) | 二叉树 | 当根节点存在左子树的时候，将左子树的右侧插入到 `root` 和 `root.Right` 中，然后 `root.Right` 指向 `root.Left` 然后，`root.Left` 指向 `nil`，然后 root 向右移动即可|
| [0115](https://leetcode-cn.com/problems/distinct-subsequences/solution/lc115-fengwei2002-by-kycu-6xrr/) | [115.不同的子序列](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/115.不同的子序列.go) | DP | 当遇到两个字符串的转换问题的时候，使用 `f[i][j]` 表示 DP 数组即可，注意这个题的数据初始化，所有的 `f[i][0]` 应该被初始化为 1|
| [0116](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/lc116-fengwei2002-by-kycu-u83a/) | [116.填充每个节点的下一个右侧节点指针](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/116.填充每个节点的下一个右侧节点指针.go) | 二叉树 | 层次遍历，将层次遍历顺序得到的 `node` 节点放入二维数组中， 遍历二维数组，每个节点指向右侧节点 |
| [0117](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/lc117-fengwei2002-by-kycu-pvjd/) | [117.填充每个节点的下一个右侧节点指针-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/117.填充每个节点的下一个右侧节点指针-ii.go) | 二叉树 | 同上 |
| [0118](https://leetcode-cn.com/problems/pascals-triangle/solution/lc118-fengwei2002-by-kycu-5q8i/) | [118.杨辉三角](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/118.杨辉三角.go) | DP | `line[j] = f[i-1][j-1] + f[i-1][j]`|
| [0119](https://leetcode-cn.com/problems/pascals-triangle-ii/solution/lc119-fengwei2002-by-kycu-nfcf/) | [119.杨辉三角-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/119.杨辉三角-ii.go) | DP | 滚动数组的优化写法，就是先按照没有滚动数组把程序写出来，然后所有的行坐标 `&1` |
| [0120](https://leetcode-cn.com/problems/triangle/solution/lc120-fengwei2002-by-kycu-rcxn/) | [120.三角形最小路径和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/120.三角形最小路径和.go) | 条件 DP | 注意边界情况的判断，不要漏掉某种情况|
| [0121](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/lc121-fengwei2002-by-kycu-38dw/) | [121.买卖股票的最佳时机](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/121.买卖股票的最佳时机.go) |tags| Content|
| [0122](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/lc122-fengwei2002-by-kycu-irmm/) | [122.买卖股票的最佳时机-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/122.买卖股票的最佳时机-ii.go) |tags| Content|
| [0123](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/lc123-fengwei2002-by-kycu-srvo/) | [123.买卖股票的最佳时机-iii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/123.买卖股票的最佳时机-iii.go) |tags| Content|
| [0124](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/lc124-fengwei2002-by-kycu-xg9w/) | [124.二叉树中的最大路径和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/124.二叉树中的最大路径和.cpp) |tags| Content|
| [0125](https://leetcode-cn.com/problems/valid-palindrome/solution/lc125-fengwei2002-by-kycu-j760/) | [125.验证回文串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/125.验证回文串.cpp) |tags| Content|
| [0126](https://leetcode-cn.com/problems/word-ladder-ii/solution/lc126-fengwei2002-by-kycu-5lcn/) | [126.单词接龙-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/126.单词接龙-ii.cpp) | BFS + DFS| Content|
| [0127](https://leetcode-cn.com/problems/word-ladder/solution/lc127-fengwei2002-by-kycu-g7g3/) | [127.单词接龙](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/127.单词接龙.cpp) | BFS | Content|
| [0128](https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/lc128-fengwei2002-by-kycu-c4ez/) | [128.最长连续序列](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/128.最长连续序列.cpp) |tags| Content|
| [0129](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/lc129-fengwei2002-by-kycu-jr9s/) | [129.求根节点到叶节点数字之和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/129.求根节点到叶节点数字之和.cpp) |tags| Content|
| [0130](https://leetcode-cn.com/problems/surrounded-regions/solution/lc130-fengwei2002-ni-xiang-si-kao-by-kyc-6s1a/) | [130.被围绕的区域](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/130.被围绕的区域.cpp) |tags| Content|
| [0131](https://leetcode-cn.com/problems/palindrome-partitioning/solution/lc131-fengwei2002-dfs-by-kycu-eow5/) | [131.分割回文串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/131.分割回文串.cpp) |tags| Content|
| 0132 | [132.分割回文串-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/132.分割回文串-ii.cpp) |tags| Content|
| 0133 | [133.克隆图](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/133.克隆图.cpp) |tags| Content|
| 0134 | [134.加油站](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/134.加油站.cpp) |tags| Content|
| 0135 | [135.分发糖果](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/135.分发糖果.cpp) |tags| Content|
| 0136 | [136.只出现一次的数字](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/136.只出现一次的数字.cpp) |tags| Content|
| 0137 | [137.只出现一次的数字-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/137.只出现一次的数字-ii.cpp) |tags| Content|
| 0138 | [138.复制带随机指针的链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/138.复制带随机指针的链表.cpp) |tags| Content|
| 0139 | [139.单词拆分](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/139.单词拆分.cpp) |tags| Content|
| 0140 | [140.单词拆分-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/140.单词拆分-ii.cpp) |tags| Content|
| 0141 | [141.环形链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/141.环形链表.cpp) |tags| Content|
| 0142 | [142.环形链表-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/142.环形链表-ii.cpp) |tags| Content|
| 0143 | [143.重排链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/143.重排链表.cpp) |tags| Content|
| 0144 | [144.二叉树的前序遍历](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/144.二叉树的前序遍历.cpp) |tags| Content|
| 0145 | [145.二叉树的后序遍历](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/145.二叉树的后序遍历.cpp) |tags| Content|
| 0146 | [146.lru-缓存机制](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/146.lru-缓存机制.cpp) |tags| Content|
| 0147 | [147.对链表进行插入排序](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/147.对链表进行插入排序.cpp) |tags| Content|
| 0148 | [148.排序链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/148.排序链表.cpp) |tags| Content|
| 0149 | [149.直线上最多的点数](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/149.直线上最多的点数.cpp) |tags| Content|
| 0150 | [150.逆波兰表达式求值](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/150.逆波兰表达式求值.cpp) |tags| Content|
| [0151](https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/lc151-fengwei2002-by-kycu-6816/) | [151.翻转字符串里的单词](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/151.翻转字符串里的单词.cpp) |tags| Content|
| [0152](https://leetcode-cn.com/problems/maximum-product-subarray/solution/lc152-fengwei2002-by-kycu-4fhy/) | [152.乘积最大子数组](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/152.乘积最大子数组.cpp) |tags| Content|
| [0153](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/lc153-fengwei2002-by-kycu-xu8a/) | [153.寻找旋转排序数组中的最小值](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/153.寻找旋转排序数组中的最小值.cpp) |tags| Content|
| 0154 | [154.寻找旋转排序数组中的最小值-ii](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/154.寻找旋转排序数组中的最小值-ii.cpp) |tags| Content|
| 0155 | [155.最小栈](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/155.最小栈.cpp) |tags| Content|

| 01 | [name](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name.cpp) |tags| Content|
| 01 | [name](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name.cpp) |tags| Content|
| 01 | [name](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name.cpp) |tags| Content|
| 01 | [name](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name.cpp) |tags| Content|
| 01 | [name](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name.cpp) |tags| Content|