/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int Pathlength = 0;
        //计算两个点之间的最短距离，然后累加
        //得出两个点构成的长方形的长和宽，然后长减去宽剩下的边数就得走直线，再加上宽的数量（走对角线的数量）
        //所以两个点之间的路径长度就和更加长的那一条边一样长
        for (int i = 1; i < points.size(); i++) {
            int width = abs(
                points.at(i).at(0) -
                points.at(i - 1).at(0));  //第一个点的横坐标减去第二个点的横坐标
            int length = abs(
                points.at(i).at(1) -
                points.at(i - 1).at(1));  //第一个点的横坐标减去第二个点的纵坐标
            Pathlength += max(width, length);
        }
        return Pathlength;
    }
};
// @lc code=end
