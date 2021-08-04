/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/*2021-08-04-15-27*/
// ? 思路解析：
/*
 * 1 排序后进行判断
 * 2 使用哈希表， unordered_set()
 *
 *
 ! --难点：
 ! -- 熟悉哈希表库的使用，unorder_map
 ! --
 */
// @lc code=start
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for (auto x : nums)
            if (S.count(x))
                return true;
            else
                S.insert(x);
        return false;
    }
};
// @lc code=end

class Solution2 {
   public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
