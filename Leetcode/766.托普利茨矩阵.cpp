/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //判断是否为左上开始到右下的所有元素都条纹相同的矩阵
        bool result = true;
        int x_length = matrix.at(0).size();
        int y_length = matrix.size();
        //从最左边的一条边的每个元素开始考虑，然后考虑最上边的一条边的每个元素
        // x+1 y+1，如果遇到了边界就停止
        //如果中间的任意一斜行不满足条件。break 直接返回结果即可
        for (int index_y = 1; index_y < y_length; index_y++) {
            for (int index_x = 1; index_x < x_length; index_x++) {
                if (matrix.at(index_y - 1).at(index_x - 1) !=
                    matrix.at(index_y).at(index_x)) {
                    result = false;
                    break;
                }
            }
        }
        for (int index_x = 1; index_x < x_length; index_x++) {
            for (int index_y = 1; index_y < y_length; index_y++) {
                if (matrix.at(index_y - 1).at(index_x - 1) !=
                    matrix.at(index_y).at(index_x)) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
