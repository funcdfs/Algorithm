/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distance = 0;
        for (int i = 0; i < arr1.size(); i++) {
            int nice = 0;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1.at(i) - arr2.at(j)) > d) {
                    nice++;
                }
            }
            if (nice == arr2.size()) {
                distance++;
            }
        }

        return distance;
    }
};
// @lc code=end
