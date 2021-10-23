/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-19-10-01*/

// depository: 
// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/edit-distance/solution/lc72-fengwei2002-jing-dian-dp-by-kycu-g3oe/


// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n == 0 || m == 0) return n + m;

        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) f[i][0] = i;
        for (int j = 1; j <= m; j++) f[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (word1[i - 1] != word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);
            }
        }

        return f[n][m];
    }
};
// @lc code=end
