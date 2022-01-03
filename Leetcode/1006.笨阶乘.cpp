/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*2022-01-01-17-05*/

// https://github.com/fengwei2002/Algorithm
// solution link:
// others: https://leetcode-cn.com/problems/clumsy-factorial/solution/fu-xue-ming-zhu-yu-dao-cheng-chu-li-ji-s-furg/
// me: https://leetcode-cn.com/problems/clumsy-factorial/solution/1006-fengwei2002-by-kycu-op9l/

// @lc code=start
class Solution {
   public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n--);

        // 将数字放入栈中
        // 乘法和除法直接进行计算，加法和减法将数字优先入栈
        while (n) {
            if (n) stk.top() *= n--;
            if (n) stk.top() /= n--;
            if (n) stk.push(n--);
            if (n) stk.push(-(n--));
        }

        int ans = 0;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
// @lc code=end
