/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-08-20-09*/
// ? 思路解析：
/*
 *
 *  用 数组偏移量 写法
 !  int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
 !  x = 0,1,0,-1 ; y = 1,0,-1,0
 */

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(); // n 代表多少行
        if (!n) return res;
        int m = matrix[0].size(); // m 代表多少列

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        // 定义偏移量数组

        vector<vector<bool>> vis(n, vector<bool>(m));
        // 定义 vis 数组 

        int x = 0, y = 0, d = 0; // 用 d 来表示方向  
        for (int i = 0; i < n * m; i++) {
            res.push_back(matrix[x][y]);
            vis[x][y] = true;

            // 求下一个格子
            int a = x + dx[d], b = y + dy[d];
            // a < 0 || a >= n || b < 0 || b >= m 代表出界了
            // vis[a][b] 
            if (a < 0 || a >= n || b < 0 || b >= m || vis[a][b]) {
                d = (d + 1) % 4; // 0123 四个方向进行循环
                a = x + dx[d], b = y + dy[d]; //更新下标
            }

            x = a, y = b; //记下来 a b 
        }

        return res;
    }
};
// @lc code=end
