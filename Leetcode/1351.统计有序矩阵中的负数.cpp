/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int NegativeTotal = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (
                int j = 0; j < grid.at(0).size();
                j++) {  //使用vscode自动补全时看一下循环变量是否已经修改，否则会浪费很多时间
                if (grid.at(i).at(j) < 0)
                    NegativeTotal++;
            }
        }
        //因为是有序矩阵，所以可以优化，从后往前遍历时，遇到一个大于0的值，那么前面的数据就不用再进行遍历了
        //为之前的每一个多加了一次if判断，少了之后的每一个的if判断
        return NegativeTotal;
    }
};
// @lc code=end
