/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
//用其他语言可以将每个数字转换为字符串，这样的运行时间更快
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    /*写一个循环得到每个数字的位数*/
    int findNumbers(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int number_weight = 1;
            while (nums.at(i) >= 10) {
                number_weight++;
                nums.at(i) = nums.at(i) / 10;
            }
            if (number_weight % 2 == 0) {
                sum++;
            }
            /* code */
        }
        return sum;
    }
};
// @lc code=end
