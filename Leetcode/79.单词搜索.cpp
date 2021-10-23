/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-18-15-54*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/word-search/solution/lc79-fengwei2002-pian-yi-liang-shu-zu-df-a10y/

// @lc code=start
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
            // 如果从某一个位置 {i, j} 开始搜索到了字符串从 0
            // 开始的完全匹配结果，返回 true
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    // 偏移量数组，上左下右

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        if (board[x][y] != word[u]) return false;
        // 某一个位置 x y 不能匹配字符串的 u 的话：结束搜索，返回 false
        // 可以执行之后的代码，说明这个位置已经匹配了

        if (u == word.size() - 1) return true;
        // 如果一直搜索到了字符串的最后一个字母，结束搜索，返回 true

        char t = board[x][y];
        board[x][y] = '.';
        // 将当前的节点置为 . 代表当前路径上已经用过这一个点了

        for (int i = 0; i < 4; i++) {  // 对四个方向进行考虑
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() ||
                board[a][b] == '.')
                continue;
            // 如果移动之后的 a 或者 b
            // 是越界的地方，或者当前路径已经用过这一个点了，
            // 跳过对这个方向的搜索
            if (dfs(board, word, u + 1, a, b)) return true;
            // 如果这个树枝可以搜索成功，那么就返回 true
            // 将任务交给 新的 [a][b] 和 word[u]
        }

        // 回溯
        board[x][y] = t;

        // 如果执行到这里，说明相等的数量小于 word
        // 的数量，并且四个方向都不能继续下去了 直接返回 false
        return false;
    }
};
// @lc code=end
