/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-06-21-15*/

// from https://github.com/fengwei2002/Algorithm

// @lc code=start
class Solution {
   public:
    bool row[9][9], col[9][9], cell[3][3][9];

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }
            }
        }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;

        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 0; i < 9; i++) {
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i]) {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;

                if (dfs(board, x, y + 1)) {
                    return true;
                }

                board[x][y] = '.';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
            }
        }

        return false;
    }
};
// @lc code=end
