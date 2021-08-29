/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
/*2021-08-21-00-45*/
// ? 思路解析：
/* 
 * 
 * 
 ! 
 !  前缀和 + 单调队列
 */


// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        vector<int> s(n * 2 + 1, 0);
        for (int i = 1; i <= n * 2; i++) s[i] = s[i - 1] + nums[(i - 1) % n];

        deque<int> q;
        q.push_back(s[0]);
        int ans = INT_MIN;
 
        for (int i = 1; i <= n * 2; i++) {
            while (!q.empty() && i - q.front() > n) q.pop_front();
            ans = max(ans, s[i] - s[q.front()]);
            while (!q.empty() && s[i] <= s[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

