/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-20-18-56*/
// ? 思路解析：
/*
 *
 *
 * 快排模板，无难点
 *
 ! --难点：
 ! --
 ! --
 */
// @lc code=start
class Solution {
   public:
    void quick_sort(int q[], int l, int r) {
        if (l >= r) return;
        int i = l - 1, r = r + 1, x = (l + r) >> 1;
    }
    void sortColors(vector<int> &nums) {
        int *array = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            array[i] = nums.at(i);
        }
        quick_sort(array, 0, nums.size() - 1);
        for (int i = 0; i < nums.size(); i++) {
            nums.at(i) = array[i];
        }
        delete[] array;
    }
};
// @lc code=end

class SolutionMy_01 {
   public:
    void sortColors(vector<int> &nums) { sort(nums.begin(), nums.end()); }
};