/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*2021-10-21-11-00*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:  单调栈的应用
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/lc84-fengwei2002-by-kycu-33ky/

// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty())
                left[i] = -1;
            else
                left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty())
                right[i] = n;
            else
                right[i] = stk.top();
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, h[i] * (right[i] - left[i] - 1));

        return ans;
    }
};
// @lc code=end
