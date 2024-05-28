/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/E
 * created: 5/10/2024, 11:19:18 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(k, 0);
        for (int i = 0; i < k; i++) cin >> a[i];  // destination
        vector<int> b(k, 0);
        for (int i = 0; i < k; i++) cin >> b[i];  // cost time

        vector<int64_t> preSum((int)b.size() + 1, 0);
        for (int i = 1; i <= (int)b.size(); i++) {
            preSum[i] = preSum[i - 1] + b[i - 1];
        }
        cerr << "bus line: ";
        dbg(a);
        cerr << "time line: ";
        dbg(b);
        dbg(preSum);

        while (q--) {
            int d = 0;
            cin >> d;
            // cout this time need how many time?
            int idx = upper_bound(a.begin(), a.end(), d) - a.begin();
            double right = 0;
            if (idx) {
                right = (double)(d - a[idx - 1]) / (double)(a[idx] - a[idx - 1]) *
                        (double)(b[idx] - b[idx - 1]);

            } else {
                right = (double)d / a[0] * b[0];
            }
            dbg(d, idx, right);
            int x = (int)(right);
            cout << x + preSum[idx] << ' ';
        }
        cout << endl;
    }

    return 0;
}
/*

*/