/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-08-19-12*/
// ? 思路解析：
/* 
 *  双指针优化时间复杂度写法 

注意这个题币不可以让 k 还是从 0 开始，因为边界值是最大值。往之间靠越来越小

 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j], j--;
            }
            else {
                result[k--] = A[i] * A[i], i++;
            }
        }
        return result;
    }
};
// @lc code=end
