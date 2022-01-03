/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2022-01-02-09-41*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// 



// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int s[60] = {};
        int ans = 0;
        for (auto x : time) { 
            ans += s[(60 - x % 60) % 60];
            s[x % 60]++;
        }

        return ans;
    }
};
// @lc code=end

