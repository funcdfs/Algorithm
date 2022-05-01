/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*2021-12-06-17-39*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/longest-consecutive-sequence/solution/lc128-fengwei2002-by-kycu-c4ez/


// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> S;
        for (auto x : nums) S.insert(x);

        int ans = 0;
        for (auto x : nums) { 
            if (S.count(x) && !S.count(x - 1)) {
                int dummy = x;
                S.erase(x);
                while (S.count(dummy + 1)) {
                    dummy++;
                    S.erase(dummy);
                }
                ans = max(ans, dummy - x + 1);
            }
        }

        return ans;
    }
};
// @lc code=end

