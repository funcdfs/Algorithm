/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

/* tags: 动态规划
 * 斐波那契 三个数版本，
 * 虽然算法是 dp， 但是变量名字我觉得还是使用它的实际意义的比较好
 */

// @lc code=start
class Solution {
   public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int index1 = 0, index2 = 0, index3 = 1, index4 = 1;
        for (int i = 3; i <= n; ++i) {
            index1 = index2;
            index2 = index3;
            index3 = index4;
            index4 = index1 + index2 + index3;
        }
        return index4;
    }
};
// @lc code=end
