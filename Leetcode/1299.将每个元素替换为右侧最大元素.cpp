/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// Time Limit Exceeded
// 14/15 cases passed (N/A)

// //创建一个函数，读入两个迭代器，传回来一个数字，将数字赋值给result
//     vector<int> replaceElements(vector<int> &arr)
//     {
//         vector<int> result;
//         result.resevre(arr.size());
//         for (int i = 0; i < arr.size() - 1; i++)
//         {
//             //这个循环用来确定前面的那一个元素
//             int max = arr.at(i + 1);
//             for (int j = i + 1; j < arr.size(); j++)
//             {
//                 //这个循环用来确定后面的元素中最大的那一个
//                 if (arr.at(j) > max)
//                     max = arr.at(j);
//             }
//             result.push_back(max);
//         }
//         result.push_back(-1); //因为最后一个数字永远是-1，所以可以偷懒
//         return result;
//         }

// 第一种暴力方法虽然可以算出来，但是有一个数据会超时，所以我的方法肯定不正确

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    //创建一个函数，读入两个迭代器，传回来一个数字，将数字赋值给result
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);                 //创建要返回的向量
        ans[n - 1] = -1;                    //最后一个元素进行初始化
        for (int i = n - 2; i >= 0; --i) {  //从倒数第二个元素开始考虑
            ans[i] = max(ans[i + 1], arr[i + 1]);
            //右面已经存在的元素和考察元素的右侧元素作比较
            //因为前一个输出结果中的元素只可能是后一个已经确定的元素和数据中后一个值中的一个
        }
        return ans;
    }
    //这种方法虽然已经很简化了，但是
    // Your runtime beats 69.29 % of cpp submissions
    // Your memory usage beats 7.14 % of cpp submissions (13.9 MB)
    //所以肯定存在更优解法
};
// @lc code=end
