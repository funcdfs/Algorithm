/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-21-00-06*/
// ? 思路解析：
/*
 *
 *
 *  快排模板，无难点
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
        int i = l - 1;
        int j = r + 1;
        int x = q[(l + r) >> 1];

        while (i < j) {
            do i++;
            while (q[i] < x);
            do j--;
            while (q[j] > x);
            if (i < j) swap(q[i], q[j]);
        }
        quick_sort(q, l, j);
        quick_sort(q, j + 1, r);  //熟记一种边界情况， qlj|qj+1r
    }
    int findKthLargest(vector<int>& nums, int k) {
        int* array = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            array[i] = nums.at(i);
        }
        quick_sort(array, 0, nums.size() - 1);
        for (int i = 0; i < nums.size(); i++) {
            nums.at(i) = array[i];
        }
        delete[] array;
        return nums.at(nums.size() - k);
    }
};
// @lc code=end
