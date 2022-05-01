/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-16-13-47*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/merge-intervals/solution/lc56-fengwei2002-da-mo-ni-by-kycu-p81r/

// @lc code=start
class Solution {
   public:
    typedef pair<int, int> PII;

    void mergeItem(vector<PII>& item) {
        vector<PII> ans;
        sort(item.begin(), item.end());

        int st = -2e9, ed = -2e9;
        for (auto i : item) {
            if (ed < i.first) {
                if (st != -2e9) ans.push_back({st, ed});
                st = i.first, ed = i.second;
            } else {
                ed = max(ed, i.second);
            }
        }

        if (st != -2e9) ans.push_back({st, ed});
        item = ans;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<PII> item;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            item.push_back({l, r});
        }

        mergeItem(item);

        for (int i = 0; i < item.size(); i++) {
            ans.push_back({item[i].first, item[i].second});
        }
        return ans;
    }
};
// @lc code=end

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        if (a.empty()) return ans;

        sort(a.begin(), a.end());
        int l = a[0][0], r = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] > r) {
                ans.push_back({l, r});
                l = a[i][0], r = a[i][1];
            } else {
                r = max(r, a[i][1]);
            }
        }

        ans.push_back({l, r});

        return ans;
    }
};