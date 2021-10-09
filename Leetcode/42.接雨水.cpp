/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*2021-10-09-19-53*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = h[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], h[i]);
        }

        rightMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], h[i]);
        }

        for (int i = 0; i < n; i++) {
            ans += (min(leftMax[i], rightMax[i]) - h[i]) * 1;
        }

        return ans;
    }
};
// @lc code=end

// 单调栈写法：
class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] <= h[i]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break;
                ans += (i - st.top() - 1) * (min(h[st.top()], h[i]) - h[top]);
            }
            st.push(i);
        }
        return ans;
    }
};
