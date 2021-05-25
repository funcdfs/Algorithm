/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (auto indice : indices) {
            rows[indice[0]]++;
            cols[indice[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((rows[i] + cols[j]) % 2)
                    res += 1;
            }
        }
        return res;
    }
};
// @lc code=end
