/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-27-20-50*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! 找规律
 !
 *
 * 优雅的解决问题
 https://leetcode-cn.com/problems/integer-to-roman/solution/lc12-fengwei2002-by-fengwei2002-r2an/
 */

// @lc code=start
class Solution {
   public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[] = {
            "M",  "CM", "D",  "CD", "C",  "XC", "L",
            "XL", "X",  "IX", "V",  "IV", "I",
        };

        string res;
        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                num -= values[i];
                res += reps[i];
            }
        }

        return res;
    }
};
// @lc code=end
