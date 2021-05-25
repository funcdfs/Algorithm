/*
 * @lc app=leetcode.cn id=1389 lang=cpp
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for (int i = 0; i < nums.size(); i++) {
            //这两个数组开始写反了。。。所以读题还是要仔细，还有变量肯定是存在实际意义的名字，不能没有实际意义
            target.emplace(target.begin() + index.at(i), nums.at(i));
            //根据变量名的实际意义来判断他的作用
        }
        return target;
    }
};
// @lc code=end
