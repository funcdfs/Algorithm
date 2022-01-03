/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-09-15-56*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// 


// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        vector<int> f(n + 1, 1e8);

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i == j) g[i][j] = true;
                
            }
        }
    }
};
// @lc code=end

