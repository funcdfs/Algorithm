/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    //可以对每一个元素都遍历一遍并同时进行统计，也可以排序完成后输出对应下标
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        vector<int> tem;
        // tem是排序前的数组
        for (int i = 0; i < nums.size(); i++) {
            tem.push_back(nums.at(i));
        }
        sort(nums.begin(),
             nums.end());  //排序算法重新总结，实际操作中用sort函数即可
        //从小到大排序后输出对应下标
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (tem[i] == nums[j]) {
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
