/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-20-13-28*/

// ? 思路解析
/*
 * 双指针算法

 * 在第二重循环和第三重循环中的 j 和 k 具有单调性，当 j 增大的同时，
 * k 可能的值只能是，j 到字符串的末尾，
 * 三次方复杂度优化到二次方复杂度
 *
 *
 *
 * ---
 * 优化： 当遇到一个元素大于零的时候，他之后的元素都不用进行考虑了
 ! --难点在于如何将结果去重
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans(0, vector<int>(0, 0));

        int n = nums.size();
        sort(nums.begin(), nums.end()); // 记得要优先排序
 
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 这一步是去掉相同的 i

            int k = n - 1; // k 是逆序开始的一个指针
            int j = i + 1; // j 是 i 后面的一个指针
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else { // 找到了一个三元组
                    ans.push_back({nums[i], nums[j], nums[k]}); // 放入三元组的写法， 不用先声明 itemAns 
                    // 在找到结果后进行去重，而不是在找到结果前进行去重
                    while (k > j && nums[k] == nums[k - 1]) k--; // 这两步是对于一个 i 去掉相同的 j 和 k
                    while (k > j && nums[j] == nums[j + 1]) j++;
                    k--, j++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end