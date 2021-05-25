/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        //给定一个矩阵，再给一个容器的宽和高
        //按照从左到右行遍历的顺序进行填充这个新的容器并且返回
        vector<vector<int>> result(r, vector<int>(c, 0));
        // r 表示行数（纵） ， c 表示列数（横坐标）
        int index_x = 0;  //容器的横坐标
        int index_y = 0;  //容器的纵坐标
        //如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；
        //否则，输出原始矩阵。
        if (r * c != nums.at(0).size() * nums.size()) {
            return nums;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.at(0).size(); j++) {
                //遍历nums的每一个数字，并将其填入容器中
                result.at(index_y).at(index_x) = nums.at(i).at(j);
                index_x++;
                if (index_x == c) {
                    index_x = 0;
                    index_y++;
                    if (index_y == r)
                        return result;
                }
            }
        }
        //注意数组的下标声明，用at的话是先指定列坐标，再指定行坐标
        return result;
    }
};
// @lc code=end
