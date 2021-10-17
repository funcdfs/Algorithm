/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-17-15-50*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/plus-one/solution/lc66-fengwei2002-gao-jing-du-jia-fa-by-k-g03q/

// @lc code=start
// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        // 从后往前考虑每一个数字
        vector<int> ans;
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int t = digits[i];
            if (t >= 10 && i - 1 != -1) {
                digits[i] = t % 10;
                digits[i - 1] += t / 10;
            }
        }
        for (int i = 0; i < digits.size(); i++) {
            cout << digits[i] << endl;
        }
        if (digits[0] >= 10) {
            ans.push_back(digits[0] / 10);
            ans.push_back(digits[0] % 10);
        } else {
            ans.push_back(digits[0]);
        }
        for (int i = 1; i < digits.size(); i++) {
            ans.push_back(digits[i]);
        }

        return ans;
    }
};

// 两次翻转，更加整洁的代码

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;

        for (auto& x : digits) {
            t += x;
            x = t % 10;
            t /= 10;
        }
        if (t) digits.push_back(t);

        reverse(digits.begin(), digits.end());

        return digits;
    }
};

// @lc code=end
