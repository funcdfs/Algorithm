/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //水平翻转一次二进制矩阵，然后再01替换一次，01替换遍历即可，水平翻转需要考虑
        //分奇数偶数，两侧 swap 即可
        int length_x = A.at(0).size();
        int length_y = A.size();
        //避免多次调用函数来求值，记录下来运行比较快
        if (length_x % 2 == 1) {
            for (int j = 0; j < length_y; j++) {
                for (int i = 0; i <= (length_x - 1) / 2; i++) {
                    swap(A.at(j).at(i), A.at(j).at(length_x - 1 - i));
                }
            }
        } else {
            for (int j = 0; j < length_y; j++) {
                for (int i = 0; i < length_x / 2; i++) {
                    swap(A.at(j).at(i), A.at(j).at(length_x - 1 - i));
                }
            }
        }
        for (int i = 0; i < length_y; i++) {
            for (int j = 0; j < length_x; j++) {
                A.at(i).at(j) = !A.at(i).at(j);  //赋值符号和等于符号要分清楚
            }
        }
        return A;
    };
};  //类声明完成后需要有一个分号！！
// @lc code=end
