/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-16-14-43*/
// ? 思路解析：
/*
 * 二分查找模板题
 * 二维数组中的二分查找
 !
 !
 */

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool answer = false;
        for (int i = 0; i < matrix.size(); i++) {
            int l = 0, r = matrix.at(i).size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (matrix.at(i).at(mid) >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (matrix.at(i).at(l) == target) answer = true;
        }

        return answer;
    }
};
// @lc code=end

class Solution_02 {
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
