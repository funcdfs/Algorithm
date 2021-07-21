/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-21-18-24*/
// ? 思路解析：
/*
 *
 *
 * acwing 模板题
 *
 ! --难点：
 ! --单调队列，将比自己小的元素剔除后不要忘记把自己再放进去
 ! --
 */
// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int* q = new int[n];
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i++) {
            if (hh <= tt && i - k + 1 > q[hh]) hh++;
            while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;
            q[++tt] = i;
            if (i >= k - 1) ans.push_back(nums[q[hh]]);
        }
        delete[] q;
        return ans;
    }
};
// @lc code=end
