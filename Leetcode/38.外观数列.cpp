/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-06-22-24*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string dummy;

            for (int j = 0; j < s.size();) {
                int k = j + 1;
                while (k < s.size() && s[k] == s[j]) k++;
                dummy += to_string(k - j) + s[j];
                j = k;
            }

            s = dummy;
        }

        return s;
    }
};

// @lc code=end
