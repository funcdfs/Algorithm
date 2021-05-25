/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
   public:
    bool judgeCircle(string moves) {
        //从头到尾的字符串可以相互抵消则可以返回终点
        int a[2] = {0, 0};
        for (int i = 0; i < moves.size(); i++) {
            if (moves.at(i) == 'R')
                a[0]++;
            if (moves.at(i) == 'L')
                a[0]--;
            if (moves.at(i) == 'U')
                a[1]++;
            if (moves.at(i) == 'D')
                a[1]--;
        }
        if (a[0] == 0 && a[1] == 0) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end
