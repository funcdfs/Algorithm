/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-23-21-33*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/search-a-2d-matrix/solution/lc74-fengwei2002-er-fen-by-kycu-0llk/

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / m][mid % m] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        return matrix[r / m][r % m] == target;
    }
};
// @lc code=end