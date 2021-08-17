/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-16-14-59*/
// ? 思路解析：
/* 
 * 二分查找模板题
 * 
 ! 
 ! 
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int l = 0, r = matrix.at(i).size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (matrix.at(i).at(mid) >= target) r = mid;
                else l = mid + 1;
            }
            if (matrix.at(i).at(r) == target) return true;
        }
        return false;
    }
};

// @lc code=end

