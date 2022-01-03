/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-06-17-57*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/surrounded-regions/solution/lc130-fengwei2002-ni-xiang-si-kao-by-kyc-6s1a/


// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        // 先考虑四周边界情况的 O，出现 O 就将那一块 O 全部变为 #
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[n - 1][j] == 'O') {
                dfs(board, n - 1, j);
            }
        }

        // 遍历棋盘，如果等于 # 的字符，就变为 O，因为这些 O 并没有被 X 字符包围
        // 否则，就全部变为 X 字符
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
    }

    void dfs(vector<vector<char>> board, int x, int y) {
        int n = board.size();
        int m = board.at(0).size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        board[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];

            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O') {
                dfs(board, a, b);
            }
        }
    }
};
// @lc code=end

