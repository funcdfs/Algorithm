/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-06*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/gray-code/solution/lc89-fengwei2002-by-kycu-rjei/

// @lc code=start
class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);  // 当 n 等于 0 的时候只有一个数字
        while (n--) {
            for (int i = ans.size() - 1; i >= 0; i--) {
                // 轴对称过去
                ans[i] *= 2;  // 每一个数字乘二，相当于前一半数字末尾补上 0
                ans.push_back(ans[i] + 1);
                // 后半部分补上 1，相当于 把这个数字乘以 2 加上一
            }
        }
        return ans;
    }
};
// @lc code=end
