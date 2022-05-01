/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-49*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/insert-interval/solution/lc57-fengwei2002-mo-ni-by-kycu-f004/

// @lc code=start
// https://github.com/fengwei2002/algorithm

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        // a 是已经排序的区间列表， b 是一个新的区间

        int k = 0;
        // 当 a 中区间的右端点小于 b 的左端点的时候，把 a 放入 ans 中
        while (k < a.size() && a[k][1] < b[0]) ans.push_back(a[k++]);

        // 当结束之后的 k 没有到达 a 的边界的时候，这时候的 a 中的一段区间和
        // 把是重叠的 这个合并后区间的左端点是 a 和 b[0] 的最小值 区间的右端点是
        // a[k][1] 和 b[1] 的最大值, 更新 b[1] 为最新的最大值
        if (k < a.size()) {
            b[0] = min(b[0], a[k][0]);
            while (k < a.size() && a[k][0] <= b[1]) b[1] = max(b[1], a[k++][1]);
        }
        ans.push_back(b);

        // 将剩余的有序部分放入
        while (k < a.size()) ans.push_back(a[k++]);
        return ans;
    }
};
// @lc code=end
