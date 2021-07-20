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
 * ---
 * 优化： 当遇到一个元素大于零的时候，他之后的元素都不用进行考虑了
 ! --难点在于如何将结果去重
 */
// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans(0, vector<int>(0, 0));
        vector<int> itemAns;
        int n = nums.size();  // -4 -1 -1 0 1 2

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // if (nums[i] > 0) return ans;
            // 对于数据来说，这一步优化反而会变慢
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 确保下一次结果中的 i 和上一次用到的 i 不一样
            int k = n - 1;
            int j = i + 1;
            while (j < k) {  // j < n && j < k
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    itemAns.push_back(nums[i]);
                    itemAns.push_back(nums[j]);
                    itemAns.push_back(nums[k]);
                    ans.push_back(itemAns);
                    itemAns.clear();
                    while (k > j && nums[k] == nums[k - 1]) k--;
                    while (k > j && nums[j] == nums[j + 1]) j++;
                    k--, j++;
                    // 在找到结果后进行去重，而不是在找到结果前进行去重
                    // -1, -1, 2,
                }
            }
        }
        return ans;
    }
};
// @lc code=end

class SolutionMy_01 {
   public:
    // 去重的写法会存在判断的局限性， [1,1,-2] 就不可以了哦~
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans(0, vector<int>(0, 0));
        vector<int> itemAns;
        if (nums.size() == 3 && nums[0] == 0 && nums[1] == 0 && nums[2] == 0) {
            ans.push_back({0, 0, 0});
            return ans;
        }
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if (nums.size() < 3) {
            return ans;
        } else {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++) {
                int k = nums.size() - 1;
                for (int j = i + 1; j < nums.size() - 1 && j < k; j++, k--) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        itemAns.push_back(nums[i]);
                        itemAns.push_back(nums[j]);
                        itemAns.push_back(nums[k]);
                        ans.push_back(itemAns);
                        itemAns.clear();
                    }
                }
            }
        }
        return ans;
    }
};

class SolutionOfficial {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                    //（使用continue比使用while进行移动更加简洁）
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};