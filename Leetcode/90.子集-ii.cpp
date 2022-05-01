/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-05*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/subsets-ii/solution/lc90-fengwei2002-by-kycu-jkwn/

// @lc code=start
class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& nums, int startIndex) {
        ans.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > startIndex &&
                nums[i] == nums[i - 1]) {  // 注意这里使用i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 去重需要排序
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end
