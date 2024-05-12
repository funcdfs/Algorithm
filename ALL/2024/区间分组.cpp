/**
 * author: https://github.com/funcdfs
 * created: 2024-04-27 19:10:13
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

    int n = 0;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    sort(a.begin(), a.end(), [](auto& a, auto& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    dbg(a);

    unordered_map<int, int> hs;
    int st = a[0][0], ed = a[0][1];
    hs[0] = 1;
    for (int i = 1; i < n;) {
        if (a[i][0] <= ed) {
            hs[i] = 0;
        } else {
            ed = a[i][1];
            hs[i] = 1;
        }
        i += 1;
    }

    for (int i = 0; i < n; i++) {
        dbg(i, hs[i], '1');
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (hs[i] == 0) {
            st = a[i][0];
            ed = a[i][1];
            idx = i;
            break;
        }
    }
    dbg(idx);
    if (idx != 0) {
        hs[idx] = 1;
        for (int i = idx + 1; i < n;) {
            dbg(i);
            if (hs[i] == 1 or a[i][0] <= ed) {
            } else {
                ed = a[i][1];
                dbg("HI");
                hs[i] = 1;
                dbg(i);
            }
            i += 1;
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        dbg(i, hs[i]);
        if (hs[i] == 0) {
            flag = false;
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
/*

*/