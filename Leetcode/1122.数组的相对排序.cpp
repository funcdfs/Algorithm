/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        // arr2 是 arr1 的子集，arr2 中没有重复元素
        vector<bool> flag(arr1.size(), false);
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1.at(j) == arr2.at(i)) {
                    result.push_back(arr1.at(j));
                    flag.at(j) = true;
                }
            }
        }
        vector<int> sort_v;
        for (int i = 0; i < arr1.size(); i++) {
            if (!flag.at(i)) {
                sort_v.push_back(arr1.at(i));
            }
        }
        sort(sort_v.begin(), sort_v.end());
        for (int i = 0; i < sort_v.size(); i++) {
            result.push_back(sort_v.at(i));
        }
        flag.clear();
        sort_v.clear();
        return result;
    }
};
// @lc code=end
