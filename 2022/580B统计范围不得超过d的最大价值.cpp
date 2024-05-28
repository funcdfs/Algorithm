// LINK: https://codeforces.com/contest/580/problem/B
// NAME: 580B. Kefa and Company, Codeforces - Codeforces Round #321 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.19-19:43:01, 2000 ms

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std; 

auto main() -> int32_t {
    int n = 0, d = 0; 
    cin >> n >> d; 
    vector<pair<int, int>> info; 
    info.reserve(n); 
    for (int i = 0; i < n; i++) {
       int m = 0, s = 0; 
       cin >> m >> s; 
       info.push_back({m, s}); 
    }
    sort(info.begin(), info.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first; 
    }); 
    vector<int64_t> sum(n + 1, 0); 
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + info[i - 1].second; 
    int64_t ans = 0; 
    int l = 0, r = 0; 
    while (l < n && r < n) {
        if (info[r].first - info[l].first < d) {
            ans = max(ans, sum[r + 1] - sum[l]); 
            r++; 
        } else {
            l++; 
        }
    }
    cout << ans << '\n'; 
    return 0; 
}

/*

580B统计范围不得超过d的最大价值

滑动窗口
*/