/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-09-19-36*/

// from https://github.com/fengwei2002/Algorithm
// 链接：https://leetcode.cn/problems/first-missing-positive/solution/lc41-fengwei2002-si-wei-ti-by-kycu-p4l2/
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (auto& x : nums) {
            // 使用 auto 如果要对数据做出修改的话，这里要用引用
            if (x != INT_MIN) {
                x--;  // 将所有数字减一，看成 0 到 n - 1,
            }
        }

        for (int i = 0; i < n; i++) {
            // nums[i] 应该存在的位置是 nums[nums[i]]
            // 因为简单换完一次的值，还有可能不是 nums[i] = i 那么就继续换，直到
            // nums[i] == i (nums[i] == nums[nums[i]])
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i &&
                   nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
// @lc code=end
class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto& x : nums) {
            if (x != INT_MIN) {
                x--;
            }
        }
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i + 1;
            }
        }
        return n + 1;
    }
};