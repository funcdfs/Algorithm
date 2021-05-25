/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 *
 * [1304] 和为零的N个唯一整数
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> sumZero(int n) {
        vector<int> result(n, 0);

        if (n % 2 == 1) {
            for (int i = 1; i <= (n - 1) / 2; i++) {
                result[i] = 2 * i;
                result[n - i] = (-2) * i;
            }
        } else {
            for (int i = 1; i <= n / 2; i++) {
                result[i - 1] = 2 * i;
                result[n - i] = (-2) * i;
            }
        }
        return result;
    }
};
// @lc code=end
