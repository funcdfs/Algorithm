/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    //非递减即后面的元素大于等于前面的元素
    int heightChecker(vector<int>& heights) {
        int result = 0;
        vector<int> init(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++) {
            sort(heights.begin(), heights.end());
        }
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != init[i]) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end
