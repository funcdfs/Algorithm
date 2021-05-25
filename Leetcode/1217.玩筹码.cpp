/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCostToMoveChips(vector<int>& chips) {
        //数组保存的是  筹码的位置
        //可以0代价相邻位置移动两步，或者1代价相邻位置移动一步

        //因为最终移动到任意位置都可以，而两步的棋子不算数
        //所以将奇数和偶数统计一遍，
        //输出 min(奇数，偶数) 代表需要走一步的数量，我太聪明了！
        unsigned int jsum = 0;
        unsigned int osum = 0;
        for (int i = 0; i < chips.size(); i++) {
            if (chips.at(i) % 2 == 1) {
                jsum++;
            } else {
                osum++;
            }
        }
        return jsum > osum ? osum : jsum;
    }
};
// @lc code=end
