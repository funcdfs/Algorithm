/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int busyStudent(vector<int>& startTime,
                    vector<int>& endTime,
                    int queryTime) {
        int result = 1;
        if (startTime.size() == 1) {
            if (startTime.at(0) == queryTime) {
                return 1;
            }
        }

        for (int i = 0; i < startTime.size(); i++) {
            if (endTime.at(i) > queryTime && startTime.at(i) < queryTime) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end
