/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-07-18-54*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 回溯
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int n, int k, int startIndex) {
        if (path.size() == k) ans.push_back(path);

        // 如果for循环选择的起始位置之后的元素个数 已经不足
        // 我们需要的元素个数了，那么就没有必要搜索了。
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};

// @lc code=end
