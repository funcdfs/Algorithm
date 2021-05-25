/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //将奇数和偶数分成两个部分，传回来
        vector<int> result(A.size(), 0);
        int index_front = 0;
        int index_end = A.size() - 1;
        for (int i = 0; i < A.size(); i++) {
            if (A.at(i) % 2 == 1) {
                result.at(index_end) = A.at(i);
                index_end--;
            } else {
                result.at(index_front) = A.at(i);
                index_front++;
            }
        }
        return result;
    }
};
// @lc code=end
