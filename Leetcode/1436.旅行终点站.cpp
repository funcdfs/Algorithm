/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        //传入的数据是由一个二维字符串数组组成的
        //考虑左右两组数据，去掉重复数据项
        //留在右边的一组中剩下的即为终点站
        bool* flag = new bool[paths.size()];
        for (int i = 0; i < paths.size(); i++) {
            flag[i] = false;
        }

        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths.size(); j++) {
                if (!flag[j] && paths.at(i).at(0) == paths.at(j).at(1)) {
                    flag[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < paths.size(); i++) {
            if (!flag[i]) {
                delete[] flag;
                return paths.at(i).at(1);
            }
        }
        delete[] flag;
        return "NULL";
    }
};
// @lc code=end
