/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-13-21-35*/

// depository: 
// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/spiral-matrix/solution/lc54-fengwei2002-pian-yi-liang-shu-zu-by-0hal/

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;

        int m = matrix[0].size();

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i++) {
            ans.push_back(matrix[x][y]);
            vis[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || vis[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return ans;
    }
};
// @lc code=end
