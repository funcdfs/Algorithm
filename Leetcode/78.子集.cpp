/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-20-23-10*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/subsets/solution/lc78-fengwei2002-by-kycu-qc7s/

// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < 1 << n; i++) {
            // i 的值是 0 到 2^n 代表一共 2^n 种可能的结果
            vector<int> path;
            // j 的值是 0 到 n
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    // 如果某一次结果的 第 j 位 是 1，那么 nums[j] 就应该在 path 中存在
                    path.push_back(nums[j]);
                }
            }
            ans.push_back(path);
        }

        return ans;
    }
};
// @lc code=end
