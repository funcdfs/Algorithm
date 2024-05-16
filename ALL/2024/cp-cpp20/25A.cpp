/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/25/problem/A
 * created: 5/7/2024, 11:40:40 AM	
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> hs1, hs2;
    for (int i = 0; i < n; i++) {
        auto& x = a[i];
        if (x & 1) {
            hs1[x] = i;
        } else {
            hs2[x] = i ;
        }
    }

    auto& [k1, v1] = *hs1.begin();
    auto& [k2, v2] = *hs2.begin();

    dbg(k1,v1,k2,v2);
    dbg((int)hs1.size(), (int)hs2.size());

    int cnt1 = count_if(a.begin(), a.end(), [&](auto& x){ return x == k1;});
    int cnt2 = count_if(a.begin(), a.end(), [&](auto& x){ return x == k2;});

    if (hs1.size() == 1 and cnt1 == 1) {
        cout << v1 + 1 << endl;
    } else if (hs2.size() == 1 and cnt2 == 1) {
        cout << v2 + 1 << endl;
    }
   
    return 0;
}
/*

*/