/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                /*这个if的条件就是DP数组的确定条件
                 *相同类型题目中只有这一句不同
                 *寻找相关dp数组，
                 *然后确定每一个元素要怎么根据前面的元素得出
                 *数学归纳法
                 */
                if (nums[i] > nums[j] && j == i - 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for (auto i : dp) {
            ans = max(ans, i);
        }
        return ans;
    }
};
// @lc code=end
