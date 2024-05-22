/**
 * name: C - AtCoder Magics
 * link: https://atcoder.jp/contests/abc354/tasks/abc354_c
 * time: 2024/5/18 20:11:56 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N = 0;
    cin >> N;
    vector<int> A(N, 0), C(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> C[i];
    }
    vector<int> idx(N, 0);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int& i1, int& i2) { return A[i1] < A[i2]; });

    vector<int> ans(0, 0);
    ans.push_back(idx[0]);
    for (int i = 1; i < N; i++) {
        while (!ans.empty()) {
            int v = ans.back();
            if (C[v] > C[idx[i]]) {
                ans.pop_back();
            } else {
                break;
            }
        }
        ans.push_back(idx[i]);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}

// #include <bits/stdc++.h> ACx6. WAx11
// using namespace std;

// #ifdef LOCAL
// #include "algo/dbg.h"
// #else
// #define dbg(...) 1
// #endif /* https://gist.github.com/funcdfs */

// auto main() -> int32_t {
//     cin.tie(nullptr), ios::sync_with_stdio(false);

//     int n = 0;
//     cin >> n;

//     vector<array<int, 3>> a(n);
//     for (int i = 0; i < n; i++) {
//         a[i][0] = i + 1;
//         cin >> a[i][1] >> a[i][2];
//     }

//     sort(a.begin(), a.end(), [](auto& x, auto& y) { return x[1] < y[1]; });
//     // for (int i = 0; i < n; i++) {
//     //     cerr << format("{0}, {1}, {2}", a[i][0], a[i][1], a[i][2]);
//     //     cerr << endl;
//     // }

//     // 对 cnt 找非严格单调递减的 所有数字，删掉

//     function<bool(pair<int, int>&, pair<int, int>&)> maxPQCmp =
//         [](pair<int, int>& x, pair<int, int>& y) {
//             return x.first < y.first;
//         };  // 弹出元素是最大值
//     priority_queue<pair<int, int>, vector<pair<int, int>>,
//                    function<bool(pair<int, int>&, pair<int, int>&)>>
//         maxPQ(maxPQCmp);

//     vector<bool> st(n + 1, true);

//     for (int i = 0; i < n; i++) {
//         if (maxPQ.size() and maxPQ.top().first >= a[i][2]) {
//             auto t = maxPQ.top();
//             maxPQ.pop();
//             st[t.second] = false;
//         }
//         maxPQ.push({a[i][2], a[i][0]});
//         // cerr << i << ' ' << maxPQ.top().first << endl;
//     }

//     int haha = 0;
//     for (int i = 1; i <= n; i++) {
//         if (st[i] == true) haha += 1;
//     }

//     cout << haha << endl;
//     for (int i = 1; i <= n;i++) {
//         if (st[i] == true) {
//             cout << i << ' ';
//         }
//     }

//     return 0;
// }
/*

*/