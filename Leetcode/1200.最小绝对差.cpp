/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        //先将无序列表进行排序，得到计算相邻元素差值绝对值最小的2n个元素
        sort(arr.begin(), arr.end());
        vector<int> Operation_result(arr.size() - 1, -1);
        for (int i = 0; i < arr.size() - 1; i++) {
            Operation_result.at(i) = abs(arr.at(i) - arr.at(i + 1));
        }
        //寻找最小值对
        int mini = Operation_result.at(0);
        for (int i = 0; i < Operation_result.size(); i++) {
            mini =
                Operation_result.at(i) < mini ? Operation_result.at(i) : mini;
        }
        //将计算结果最小的2n对值赋值到二维数组中并返回
        for (int i = 0; i < Operation_result.size(); i++) {
            if (Operation_result.at(i) == mini) {
                vector<int> n_2;
                n_2.push_back(arr.at(i));
                n_2.push_back(arr.at(i + 1));
                result.push_back(n_2);
            }
        }
        return result;
    }
};
// @lc code=end
