/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*2021-10-21-11-00*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link: 特别牛逼的思路
// https://leetcode-cn.com/problems/maximal-rectangle/solution/lc85-fengwei2002-by-kycu-fr0x/

// @lc code=start
class Solution {
   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> h(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i != 0) {
                        h[i][j] = 1 + h[i - 1][j];
                    } else {
                        h[i][j] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, cal(h[i]));
        return ans;
    }

    int cal(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n);

        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) {
                left[i] = -1;
            } else {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) {
                right[i] = n;
            } else {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, h[i] * (right[i] - left[i] - 1));
        return ans;
    }
};
// @lc code=end
