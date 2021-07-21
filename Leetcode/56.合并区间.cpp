/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-21-00-15*/
// ? 思路解析：
/*
 * ACWing 模板题
 * internal：形容词: 内部, 内, 内置, 国内, 体内, 内在的
 * intervals : 间隔，时间
 *
 ! --难点：
 ! -- https://www.acwing.com/activity/content/code/content/1415587/
 ! --
 */
// @lc code=start
typedef pair<int, int> PII;
class Solution {
   public:
    void mergeSegs(vector<PII>& segs) {
        vector<PII> res;

        sort(segs.begin(), segs.end());
        // 根据左边界的大小进行排序

        int st = -2e9, ed = -2e9;
        // 定义左右边界为负无穷， 无穷值得大小定义为  == -2 * （最大数据范围）
        for (auto seg : segs)
            if (ed < seg.first) {
                // 如果一个区间的左边界 大于之前确定好的右边界，
                // 说明他是一个新的区间，把他放入结果 vector 中
                if (st != -2e9) res.push_back({st, ed});
                // 同时更新新的区间 起始值
                st = seg.first, ed = seg.second;
            } else
                // 否则就去，把右边界的值更新掉
                ed = max(ed, seg.second);

        if (st != -2e9) res.push_back({st, ed});
        segs = res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<PII> segs;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            segs.push_back({l, r});
        }
        mergeSegs(segs);
        for (int i = 0; i < segs.size(); i++) {
            vector<int> itemAns;
            itemAns.push_back(segs[i].first);
            itemAns.push_back(segs[i].second);
            ans.push_back(itemAns);
            itemAns.clear();
        }
        return ans;
    }
};
// @lc code=end
