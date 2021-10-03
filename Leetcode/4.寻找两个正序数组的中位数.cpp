/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-03-20-52*/

//from https://github.com/fengwei2002/Algorithm
/* 
 !
 !
 * 高阶二分
 *
 */

// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();  // 求总数

        // 分两种情况
        if (tot % 2 == 0) {
            // 如果总数是偶数的话
            int left = find(nums1, 0, nums2, 0, tot / 2);
            int right = find(nums1, 0, nums2, 0, tot / 2 + 1);
            return (left + right) / 2.0;
            // 答案就是中间两个数字的平均数
        } else {
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
            // 否则是奇数，直接返回中间那一个元素
        }
    }

    // 在两个数组分别从 i j 开始到数组结束范围内，寻找第 k 小的数字
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j)
            return find(nums2, j, nums1, i, k);  // 假定第一个数组比较短

        if (k == 1) {  // 当 k 等于 1 的时候可以进行结束
            if (nums1.size() == i)  // 说明第一个数组是空的
                return nums2[j];    // 只能返回第二个数组
            else
                return min(nums1[i], nums2[j]);
        }  // 取两个数组前两个数字的最小值

        if (nums1.size() == i)
            return nums2[j + k - 1];  // 第二个边界，如果第一个数组是空的话，
        // 直接返回第二个数组的第 k 个元素

        int si = min((int)nums1.size(), i + k / 2);
        int sj = j + k / 2;
        // si 和 sj 是 第 k / 2 之后的下一个位置
        // 根据边界值判定缩小范围
        if (nums1[si - 1] > nums2[sj - 1])  // 说明 nums2 的后半段没有用
            return find(nums1, i, nums2, sj, k - (sj - j));
        else
            return find(nums1, si, nums2, j, k - (si - i));  // 把 s1 的部分删掉
    }
};
// @lc code=end

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 0) {
            double left = find(nums1, 0, nums2, 0, tot / 2);
            double right = find(nums1, 0, nums2, 0, tot / 2 + 1);
            ans = (left + right) / 2.0;
        } else {
            ans = find(nums1, 0, nums2, 0, tot / 2 + 1);
        }

        return ans;
    }

    double find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) {
            return find(nums2, j, nums1, i, k);
        } 

        if (k == 1) {
            if (nums1.size() == i)
                return nums2[j + k - 1];
            else
                return min(nums1[i], nums2[j]);
        }

        if (nums1.size() == i) {
            return nums2[j + k - 1];
        }

        int newi = min((int)nums1.size(), i + k / 2);
        int newj = j + k / 2;
        if (nums1[newi - 1] > nums2[newj - 1]) {
            return find(nums1, i, nums2, newj, k - (newj - j));
        } else {
            return find(nums1, newi, nums2, j, k - (newi - i));
        }
    }
};