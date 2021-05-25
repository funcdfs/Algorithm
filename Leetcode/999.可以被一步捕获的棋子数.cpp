/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numRookCaptures(vector<vector<char>>& board) {
        int result = 0;
        /*找到所有的车*/
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    /*为所有的车执行上下左右的对应操作*/
                    for (int shang = i - 1; shang > 0; shang--) {
                        if (board[shang][j] == 'p') {
                            result++;
                            break;
                        }
                        if (board[shang][j] == 'B') {
                            break;
                        }
                    }
                    for (int xia = i + 1; xia < 8; xia++) {
                        if (board[xia][j] == 'p') {
                            result++;
                            break;
                        }
                        if (board[xia][j] == 'B') {
                            break;
                        }
                    }
                    for (int zuo = j - 1; zuo > 0; zuo--) {
                        if (board[i][zuo] == 'p') {
                            result++;
                            break;
                        }
                        if (board[i][zuo] == 'B') {
                            break;
                        }
                    }
                    for (int you = j + 1; you < 8; you++) {
                        if (board[i][you] == 'p') {
                            result++;
                            break;
                        }
                        if (board[i][you] == 'B') {
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
