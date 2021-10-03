/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-26-20-57*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 题解：
 https://leetcode-cn.com/problems/palindrome-number/solution/lc9-fengwei2002-by-fengwei2002-8kg0/
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int f = x;
        long long ans = 0;

        while (f > 0) {
            ans = ans * 10 + f % 10;
            f = f / 10;
        }

        return ans == x;
    }
};
// @lc code=end

class Solution_转换为字符串 {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};
