/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;
/*2021-09-22-11-18*/
// ? 思路解析：
/* 
 * 
 * 
 ! 
 ! https://www.acwing.com/activity/content/code/content/1809961/
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int, int> hash;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            hash[s[j]]++;
            while (hash[s[j]] > 1) hash[s[i++]]--;
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
// @lc code=end

