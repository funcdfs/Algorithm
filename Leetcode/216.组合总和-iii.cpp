/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-07-19-28*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int numsCount, int targetSum, int sum, int startIndex) {
        if (path.size() == numsCount) {
            if (sum == targetSum) ans.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);

            dfs(numsCount, targetSum, sum, i + 1);

            sum -= i;
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum3(int numsCount, int targetSum) {
        dfs(numsCount, targetSum, 0, 1);
        return ans;
    }
};

// @lc code=end
