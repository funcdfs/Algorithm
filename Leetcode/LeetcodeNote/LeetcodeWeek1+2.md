LeetCode 1-30 题

>DATE 2021-09-25

>DATE 2021-09-25

| number | name | tags | steps  |
| ------ | ---- | ---- | ------ |
| 0001 | [1.两数之和](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/1.两数之和.cpp) |数组 哈希表| 遍历哈希表，同时进行数据存储 |
| 0002 | [2.两数相加](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/2.两数相加.cpp) |链表 高精度加法| 在链表上进行手算加法模拟|
| 0003 | [3.无重复字符的最长子串](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/3.无重复字符的最长子串.cpp) |字符串 哈希表| `hash[s[j]]++;` `while (hash[s[j]] > 1) hash[s[i++]]--` `ans = max(ans, j - i + 1);` |

>DATE 2021-09-26

| number | name | tags | steps  |
| ------ | ---- | ---- | ------ |
| 0004 | [4.寻找两个正序数组的中位数](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/4.寻找两个正序数组的中位数.cpp) |数组 二分| 每次省略一遍 k / 2 之前的元素|
| 0005 | [5.最长回文子串](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/5.最长回文子串.cpp) |字符串| 枚举所有中点值，左右扩大范围|
| 0006 | [6.z-字形变换](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/6.z-字形变换.cpp) |数组 找规律| 列举之后找规律即可 2n - 2 的等差数列|

>DATE 2021-09-26

| number | name | tags | steps  |
| ------ | ---- | ---- | ------ |
| 0007 | [7.整数反转](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/7.整数反转.cpp) |数组 回文串| 如何优雅的判断是否越界|
| 0008 | [8.字符串转换整数-atoi](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/8.字符串转换整数-atoi.cpp) |字符串 模拟| 模拟操作即可|
| 0009 | [9.回文数](https://raw.githubusercontent.com/fengwei2002/Algorithm/main/Leetcode/9.回文数.cpp) |数组 回文串| 同第七题，可以转换为字符串写 `to_string + reverse`|

