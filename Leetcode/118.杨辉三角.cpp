/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
// =

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        //构造一个正方形的二维数组
        vector<vector<int>> result(numRows, vector<int>(numRows, 0));
        //将相应的数字先填到靠左侧的三角形中
        for (int i = 0; i < numRows; i++) {
            result.at(i).at(0) = 1;  //初始化三角的左侧的边界值
            result.at(i).at(i) = 1;  //初始化三角的右侧的边界值
        }
        //内容的计算
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < numRows; j++) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        //最后将等于 0 的单位(空白单位)弹出数组的空间
        for (int i = 0; i < numRows; i++) {
            for (int j = numRows - i - 1; j > 0; j--) {
                result.at(i).pop_back();
            }
        }
        //返回结果
        return result;
    }
};
// @lc code=end
