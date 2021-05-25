/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    //从小到大排序
    vector<int> sortedSquares(vector<int>& A) {
        //根本不用新开辟空间，直接操作
        for (int i = 0; i < A.size(); i++) {
            A.at(i) = A.at(i) * A.at(i);
        }
        sort(A.begin(), A.end());
        return A;
    }
};
// @lc code=end
