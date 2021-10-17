/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-14-14-56*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/permutation-sequence/solution/lc60-fengwei2002-ji-shu-fa-by-kycu-wpwd/

// @lc code=start
class Solution {
   public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> st(10);
        for (int i = 0; i < n; i++) {
            int fact = 1;
            for (int j = 1; j <= n - i - 1; j++) fact *= j;

            for (int j = 1; j <= n; j++) {
                if (!st[j]) {
                    if (fact < k)
                        k -= fact;
                    else {
                        res += to_string(j);
                        st[j] = true;
                        break;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

// 使用 next_permutation

class Solution {
   public:
    string getPermutation(int n, int k) {
        string ans = "";
        for (int i = 1; i <= n; i++) {
            ans += to_string(i);
        }
        for (int i = 0; i < k - 1; i++) {
            next_permutation(ans.begin(), ans.end());
        }
        return ans;
    }
};