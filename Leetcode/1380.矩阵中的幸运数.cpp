/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        //返回行中最小，列中最大的元素
        int length_x = matrix.at(0).size();
        int length_y = matrix.size();
        vector<int> result;

        for (int i = 0; i < length_y; i++) {
            //找到一行中的最小值
            int mini_x = matrix.at(i).at(0);
            int mini_x_index = 0;
            for (int j = 0; j < length_x; j++) {
                if (matrix.at(i).at(j) < mini_x) {
                    mini_x = matrix.at(i).at(j);
                    mini_x_index = j;
                }
            }
            //找到最小值对应的那一列的最大值
            int max_y = matrix.at(0).at(mini_x_index);
            for (int k = 0; k < length_y; k++) {
                if (matrix.at(k).at(mini_x_index) > max_y) {
                    max_y = matrix.at(k).at(mini_x_index);
                }
            }
            if (max_y == mini_x) {
                result.push_back(max_y);
            }
        }
        return result;
    }
};
// @lc code=end
