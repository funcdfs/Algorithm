/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
 */

// @lc code=start

// for (int i = 0; i < nums.size(); i++);
//         {
//             if (2 * i > nums.size() - 2)
//                 break;
//             for (int j = 0; i < nums.at(2 * i); j++)
//             {
//                 result.push_back(nums.at(2 * i + 1));
//             }
//         } Time Limit Exceeded，所以换一个方法

// vector<int> decompressRLElist(vector<int> &nums)
//     {
//         vector<int> result;
//         for (int i = 0; i <= nums.size() / 2 - 1; i++)
//         //手动举例即可确定数组边界 {
//         //end()返回最后一个元素的后一个元素的迭代器
//             vector<int>::iterator it = result.end() - 1;
//             result.insert(it, nums.at(2 * i), nums.at(2 * i + 1));
//         }
//         return result;
//     } //end方法使用错误，所以就错了

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i <= nums.size() / 2 - 1;
             i++)  //手动举例即可确定数组边界
        {
            // end()返回最后一个元素的后一个元素的迭代器
            vector<int>::iterator it = result.end();
            result.insert(it, nums.at(2 * i), nums.at(2 * i + 1));
            //传入的迭代器代表应该写入的位置所以不用 end()-1！！！
        }
        return result;
    }
};
// @lc code=end
