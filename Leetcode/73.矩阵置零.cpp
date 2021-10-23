/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-19-11-04*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/set-matrix-zeroes/solution/lc73-fengwei2002-by-kycu-z34l/

// @lc code=start
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 0, row0 = 0;
        if (matrix.empty()) return;

        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = 1;
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                row0 = 1;
                break;
            }
        }  // 用两个值记录第一列和第一行是否有 0

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }  // 用第一行和第一列的元素记录 矩阵的其余部分

        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }  // 设置 除第一列和第一行以外的 0

        if (col0 == 1) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        if (row0 == 1) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }  // 设置 第一行和第一列的 0
    }
};
// @lc code=end
