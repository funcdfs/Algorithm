/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <stirng.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-05-21-47*/

// from https://github.com/fengwei2002/Algorithm
//  https://leetcode.cn/problems/valid-sudoku/

// @lc code=start
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];

        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';  // 转换为 0 - 8 的数字
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int t = board[j][i] - '1';
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }

        // 判断小方格
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                memset(st, 0, sizeof st);

                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (board[i + x][j + y] != '.') {
                            int t = board[i + x][j + y] - '1';
                            if (st[t]) return false;
                            st[t] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
