LeetCode 1-30 题

``` cpp
// LeetCode 题解区搜索 fengwei2002
// https://github.com/fengwei2002/algorithm
```

| SOLUTIONLINK | AC CODE | TAGS | STEPS |
| ------ | ---- | ---- | ------ |
| [0001](https://leetcode-cn.com/problems/two-sum/solution/lc1-fengwei2002-ha-xi-biao-by-fengwei200-t94y/) | [1.两数之和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/1.两数之和.cpp) |数组 哈希表| 遍历哈希表，同时进行数据存储 |
| [0002](https://leetcode-cn.com/problems/add-two-numbers/solution/lc2-fengwei2002-mo-ni-gao-jing-du-jia-fa-ng51/) | [2.两数相加](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/2.两数相加.cpp) |链表 高精度加法| 在链表上进行手算加法模拟|
| [0003](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/lc-3-fengwei2002-ha-xi-biao-by-fengwei20-nj6v/) | [3.无重复字符的最长子串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/3.无重复字符的最长子串.cpp) |字符串 哈希表| `hash[s[j]]++;` `while (hash[s[j]] > 1) hash[s[i++]]--` `ans = max(ans, j - i + 1);` |
| [0004](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/lc4-fengwei2002-gao-jie-er-fen-by-fengwe-pvjd/) | [4.寻找两个正序数组的中位数](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/4.寻找两个正序数组的中位数.cpp) |数组 二分| 每次省略一遍 k / 2 之前的元素|
| [0005](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/lc5-fengwei2002-shuang-zhi-zhen-by-fengw-rdy2/) | [5.最长回文子串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/5.最长回文子串.cpp) | 字符串| 枚举所有中点值，左右扩大范围 |
| [0006](https://leetcode-cn.com/problems/zigzag-conversion/solution/lc6-fengwei2002-zhao-gui-lu-by-fengwei20-p6nc/) | [6.z-字形变换](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/6.z-字形变换.cpp) |数组 找规律| 列举之后找规律即可 2n - 2 的等差数列|
| [0007](https://leetcode-cn.com/problems/reverse-integer/solution/lc7-fengwei2002-qiao-miao-chu-li-chao-gu-q0we/) | [7.整数反转](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/7.整数反转.cpp) |数组 回文串| 如何优雅的判断是否越界|
| [0008](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/lc8-fengwei2002-by-fengwei2002-sg6u/) | [8.字符串转换整数-atoi](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/8.字符串转换整数-atoi.cpp) |字符串 模拟| 模拟操作即可，包含如何优雅的处理模拟运算过程中的 int 整型溢出|
| [0009](https://leetcode-cn.com/problems/palindrome-number/solution/lc9-fengwei2002-by-fengwei2002-8kg0/) | [9.回文数](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/9.回文数.cpp) |数组 模拟| 同第七题，可以转换为字符串写 `to_string + reverse`，注意要先将数据备份一遍，然后再进行比较|
| [0010](https://leetcode-cn.com/problems/regular-expression-matching/solution/lc10-fengwei2002-by-fengwei2002-6nmz/) | [10.正则表达式匹配](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/10.正则表达式匹配.cpp) |DP **hard**| 只能说原题出来的时候会写就好了，两个字符串序列的问题要用二维 DP （加上类似于完全背包的一个优化）来解决|
| [0011](https://leetcode-cn.com/problems/container-with-most-water/solution/lc11-fengwei2002-by-fengwei2002-kpan/) | [11.盛最多水的容器](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/11.盛最多水的容器.cpp) |贪心 双指针| 这个题也是见过就会写，左右两个指针，每次移动最小的那一个指针，即可求得最佳方案|
| [0012](https://leetcode-cn.com/problems/integer-to-roman/solution/lc12-fengwei2002-by-fengwei2002-r2an/) | [12.整数转罗马数字](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/12.整数转罗马数字.cpp) |打表 找规律 | 如何优雅的处理罗马数字转换的问题，找出 13 个字母串 |
| [0013](https://leetcode-cn.com/problems/roman-to-integer/solution/lc13-fengwei2002-by-fengwei2002-dfdr/) | [13.罗马数字转整数](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/13.罗马数字转整数.cpp) |找规律| 反方向的，一个数字一个数字处理即可|
| [0014](https://leetcode-cn.com/problems/longest-common-prefix/solution/lc14-fengwei2002-by-fengwei2002-pty7/) | [14.最长公共前缀](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/14.最长公共前缀.cpp) |字符串| 遍历，然后在字符不同的位置返回即可|
|[0015](https://leetcode-cn.com/problems/3sum/solution/lc15-fengwei2002-by-fengwei2002-fqnv/) | [15.三数之和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/15.三数之和.cpp) |双指针| 注意这个题的去重位置|
| [0016](https://leetcode-cn.com/problems/3sum-closest/solution/lc16-fengwei2002-by-fengwei2002-9s40/) | [16.最接近的三数之和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/16.最接近的三数之和.cpp) |双指针 细节| 注意根据距离更新 ans 的写法|
| [0017](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/lc17-fengwei2002-by-fengwei2002-3oj4/) | [17.电话号码的字母组合](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/17.电话号码的字母组合.cpp) |DFS 搜索| 遇到dfs 题目可以画一颗树，使用全排列的思路和写法即可|
| [0018](https://leetcode-cn.com/problems/4sum/solution/lc-18-fengwei2002-by-fengwei2002-3hk4/) | [18.四数之和](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name03.cpp) |双指针| 双指针可以将 On^2 优化为 O(n)，同三指针|
| [0019](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/lc-19-fengwei2002-by-fengwei2002-e11l/) | [19.删除链表的倒数第-n-个结点](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/19.删除链表的倒数第-n-个结点.cpp) |链表 | 用 dummy 节点指向头节点，first 指针始终和 second 指针距离为 n|
| [0020](https://leetcode-cn.com/problems/valid-parentheses/solution/lc20-fengwei2002-by-fengwei2002-hgve/) | [20.有效的括号](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/20.有效的括号.cpp) |栈 模拟| 使用栈的经典题目，可以使用哈希表存储括号，也可以使用 ASCII 码来简写代码|
| [0021](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/lc21-fengwei2002-by-fengwei2002-wusr/) | [21.合并两个有序链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/21.合并两个有序链表.cpp) |链表 归并排序| 二路归并，小的放进去，然后对传入的两个链表取空即可|
| [0022](https://leetcode-cn.com/problems/generate-parentheses/solution/lc22-fengwei2002-dfs-by-fengwei2002-5eum/) | [22.括号生成](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/22.括号生成.cpp) |DFS | 左括号大于右括号的情况下， 就可以继续生成括号|
| [0023](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/lc23-fengwei2002-you-xian-ji-dui-lie-dui-rt2s/) | [23.合并k个升序链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/23.合并k个升序链表.cpp) |优先级队列（堆）| 放入堆中的数据已经按照从小到大进行了排序，弹出堆顶最小的那一个 链表，拼接到 tail 后面，再次放入 heap 中，这样每次取出来的 链表都是最小的那一个|
| [0024](https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/lc24-fengwei2002-lian-biao-mo-ni-by-feng-wo5e/) | [24.两两交换链表中的节点](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/24.两两交换链表中的节点.cpp) |链表 细节模拟| 建议链表题目画图理解|
| [0025](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/lc25-fengwei2002-lian-biao-by-fengwei200-du31/) | [25.k-个一组翻转链表](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/25.k-个一组翻转链表.cpp) |链表 细节模拟| 链表题目慢慢写就好了，仔细一点|
| [0026](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/lc26-fengwei2002-uniquehan-shu-by-fengwe-7ki8/) | [26.删除有序数组中的重复项](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/26.删除有序数组中的重复项.cpp) |手写 unique 函数| 这个写法很简洁，建议背诵|
| [0027](https://leetcode-cn.com/problems/remove-element/solution/lc27-fengwei2002-tong-lc26-by-fengwei200-8yg4/) | [27.移除元素](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/27.移除元素.cpp) |同上| 只保留值不等于 val 的元素 `if (nums[i] != val) nums[k++] = nums[i];`|
| [0028](https://leetcode-cn.com/problems/implement-strstr/solution/lc28-fengwei2002-shou-xie-kmp-by-fengwei-0h4w/) | [28.实现-str-str](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/28.实现-str-str.cpp) |手写 KMP| KMP 没什么好说的，理解之后把它背烂就好了|
| [0029](https://leetcode-cn.com/problems/divide-two-integers/solution/lc29-fengwei2002-wei-yun-suan-mo-ni-by-f-zzmi/) | [29.两数相除](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/29.两数相除.cpp) |进制 模拟除法| 用进制原理模拟除法，很巧妙|
| [0030](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/lc30-fengwei2002-ha-xi-biao-hua-dong-chu-17hz/) | [30.串联所有单词的子串](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/30.串联所有单词的子串.cpp) |哈希表 滑动窗口 **hard**| 设计很巧妙，按照起始位置对于 wordlenght 的余数分组起始位置，考察滑动窗口中的某一个单词对应的数量和标准数量的差别，遇到正确匹配放入结果中|
