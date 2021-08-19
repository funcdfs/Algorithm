/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-18-10-09*/
// ? 思路解析：
/*
 *
 *
 !
 !
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        // 相比于之前的问题，这里的房屋连成了一个环
        // 可以将数组前面放入一个最后一个元素，后面在放入一个第一个元素
        // f[i] 代表到达 第 i 个房屋的时候，可以拿到的最大金额
        // max
        // f[i] = f[i - 1]
        //      = f[i - 2] + w[i]
        // 由于两次计算了 头或者 尾 的最大值，结果再减去一个对应的值即可
        int n = nums.size() - 1;
        vector<int> f(n + 1, 0);
        if (nums.size() > 1) {
            f[0] = max(nums[n], nums[0]);
            f[1] = max(f[0], nums[n] + nums[1]);
            for (int i = 2; i <= n; i++) {
                f[i] = max(f[i - 1], f[i - 2] + nums[i]);
            }
            f[n] -= f[0];
            for (int i = 0; i < f.size(); i++) {
                cout << f[i] << ' ';
            }
        } else {
            f[0] = nums[0];
        }
        return f[n];
    }
};
// @lc code=end
