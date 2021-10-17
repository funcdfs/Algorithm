/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-13-23-25*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/length-of-last-word/solution/lc58-fengwei2002wang-su-ti-by-kycu-4e6h/

// @lc code=start
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0;) {
            while (i > 0 && s[i] == ' ') i--;
            while (i >= 0 && s[i] != ' ') ans++, i--;
            break;
        }
        return ans;
    }
};
// @lc code=end
