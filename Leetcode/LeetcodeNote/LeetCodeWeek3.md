LeetCode 31-50 题

``` cpp
// LeetCode 题解区搜索 fengwei2002
// https://github.com/fengwei2002/algorithm
```

| SOLUTIONLINK | AC CODE | TAGS | STEPS |
| ------ | ---- | ---- | ------ |
| [0031](https://leetcode-cn.com/problems/next-permutation/solution/lc-fengwei2002-zhao-gui-lu-by-fengwei200-w72c/) | [31.下一个排列](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/31.下一个排列.cpp) |找规律| 从后往前找到第一个非逆序的数字，从这个数字从前往后开始找大于他的最小的那一个数字， 交换两个数字，然后要让从这个数字之后的数字排列最小，所以再执行 `reverse(nums.begin() + k, nums.end())`|
| [0032](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/lc32-fengwei2002-zhan-de-gao-nan-du-ying-uaye/) | [32.最长有效括号](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/32.最长有效括号.cpp) |栈 **HRAD**| 太难了这个题，只要保证原题出现会写就可以了。计算每一个右括号对应的合法区间的最大长度，长度值是 栈中未匹配的左括号的下一个坐标|
| [0033](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/lc-33-fengwei200-liang-ci-er-fen-by-feng-j6s5/) | [33.搜索旋转排序数组](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/33.搜索旋转排序数组.cpp) |二分查找| 两次二分查找，第一次确定递增区间结束的位置  第二次依据 target 的值，确定要在哪一个区间中进行 target 的二分查找|
| [0034](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lc34-fengwei2002-liang-ci-er-fen-cha-zha-j2ys/) | [34.在排序数组中查找元素的第一个和最后一个位置](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp) |二分查找| 两次二分查找，二分查找经典模板题|
| [0035](https://leetcode-cn.com/problems/search-insert-position/solution/lc35-fengwei2002-er-fen-mo-ban-ti-by-fen-4i6e/) | [35.搜索插入位置](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/35.搜索插入位置.cpp) |二分查找| 一次二分查找，注意大于 `target` 的要返回 `l + 1` 即可|
| [0036](https://leetcode-cn.com/problems/valid-sudoku/solution/lc36-fengwei2002-cbao-li-by-fengwei2002-yby9/) | [36.有效的数独](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/36.有效的数独.cpp) |模拟 暴力| 直接开一个 `bool[9]`, 搜索行，搜索列，搜索 `9 * 9` 的小方格，如果都匹配就返回 true|

---

| number01 | [name01](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name01.cpp) |tags| Content|
| number02 | [name02](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name02.cpp) |tags| Content|
| number03 | [name03](https://github.com/fengwei2002/Algorithm/blob/main/Leetcode/name03.cpp) |tags| Content|
