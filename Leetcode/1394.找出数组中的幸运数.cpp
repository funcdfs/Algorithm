/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLucky(vector<int>& arr) {
        //返回最大的  出现频次和它的数值大小相等的数
        //不存在返回 -1

        //可以用一个二维数组来保存对应的出现次数，但有点浪费
        //可以用两次循环来缩减空间！
        int result = -1;
        for (int i = 0; i < arr.size(); i++) {
            // frequency 用来统计出现的总次数
            int frequency = 0;
            for (int j = 0; j < arr.size(); j++) {
                if (arr.at(j) == arr.at(i)) {
                    frequency++;
                }
            }
            if (frequency == arr.at(i)) {
                result = max(result, arr.at(i));  //因为数据范围都是正数
            }
        }
        return result;
    }
};
// @lc code=end
