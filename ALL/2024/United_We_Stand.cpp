/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF1859A
 * created: 5/13/2024, 4:19:30 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (set<int>(a.begin(), a.end()).size() == 1) {
        cout << -1 << endl;
    } else {
        sort(a.begin(), a.end());
        int right = a.back();
        int rightIdx = a.size() - 1;
        int cnt = 1;
        while (rightIdx - 1 >= 0 and a[rightIdx - 1] == right)
            rightIdx -= 1, cnt += 1;
        dbg(a, rightIdx);
        cout << rightIdx << ' ' << cnt << endl;
        assert(rightIdx + cnt == n);
        for (int i = 0; i < rightIdx; i++) {
            cout << a[i] << " \n"[i == rightIdx - 1];
        }
        for (int i = rightIdx; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
/*

*/