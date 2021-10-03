/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-01-20-47*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 写DFS 问题的时候画一个类似于 全排列问题的树
 然后将树转换为代码

 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;

        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int u, string path) {  // digits,当前使第几位，路径
        if (u == digits.size())
            ans.push_back(path);  // 如果 u 已经等于最后一位了
        else {  // 否则遍历当前的这一位可以取哪些字符
            for (auto c : strs[digits[u] - '0']) {
                dfs(digits, u + 1, path + c);
            }
        }
    }
};
// @lc code=end
