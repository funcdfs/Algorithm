/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-06-21-38*/

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/palindrome-partitioning/solution/lc131-fengwei2002-dfs-by-kycu-eow5/

// @lc code=start
class Solution {
   public:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        f = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int j = 0; j < n; j++) {
            for (int i = j; i >= 0; i--) {
                if (i == j) {
                    // 如果只有一个字符的话，
                    f[i][j] = true;
                } else if (s[i] == s[j]) {
                    // 如果 s[i] == s[j] 的话，
                    //          f[i + 1][j - 1] == true
                    //          只有两个相等的字符的话 ：去除边界两个值之后的区间长度小于 0 
                    if ((j - 1) - (i + 1) < 0 || f[i + 1][j - 1]) {
                        f[i][j] = true;
                    }
                }
            }
        }

        dfs(s, 0);

        return ans;
    }

    void dfs(string& s, int u) {
        // u 表示当前搜索到了第几位
        if (u == s.size()) ans.push_back(path);
        else {
            for (int i = u; i < s.size(); i++) {
                if (f[u][i] == true) {
                    // 说明，u 到 i 这一段字符串是一个回文串
                    path.push_back(s.substr(u, i - u + 1));

                    dfs(s, i + 1);

                    path.pop_back();
                }
            }
        }
    }
};
// @lc code=end
