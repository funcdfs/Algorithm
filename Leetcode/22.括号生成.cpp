/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-02-18-04*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! DFS
 ! 生成所有可能的有效括号组合

 * 左括号大于右括号的情况下， 就可以继续生成括号
 * 左括号数量等于 右括号数量 等于 pairCount，就可以作为答案返回
 * 
 * 如果 左括号数量没有填满，那么久可以放入左括号
 * 如果 右括号的数量没有填满，并且左括号数量 比 右括号数量 多， 那么就可以放入 右括号
 */

// @lc code=start
class Solution {
   public:
    vector<string> ans;

    vector<string> generateParenthesis(int pairCount) {
        dfs(pairCount, 0, 0, "");
        return ans;
    }
    // pc: pairCount
    // lpc: leftPairCount
    // rpc: rightPairCount
    void dfs(int pc, int lpc, int rpc, string ansItem) {
        if (lpc == pc && rpc == pc) {
            ans.push_back(ansItem);
        } else {
            if (lpc < pc) {
                dfs(pc, lpc + 1, rpc, ansItem + '(');
            }
            if (rpc < pc && lpc > rpc) {
                dfs(pc, lpc, rpc + 1, ansItem + ')');
            }
        }
    }
};
// @lc code=end
