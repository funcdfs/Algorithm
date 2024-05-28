/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1692/problem/F
 * created: 5/7/2024, 1:41:07 PM	
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
        int n = 0;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        auto check = [&]() -> bool {
            // a_i + a_j + a_k mod 10 === 3
            unordered_map<int, int> hs;
            for (auto& x : a) hs[x % 10] += 1;
            auto work = [&](int x, int y, int z) -> bool {
                dbg(x, y, z);
                if ((x + y + z) % 10 != 3) return false;
                if (x == y and y == z) {
                    if (hs[x] < 3) return false;
                } else if (x == y) {
                    if (hs[y] < 2) return false;
                } else if (y == z) {
                    if (hs[y] < 2) return false;
                } else if (x == z) {
                    if (hs[x] < 2) return false;
                }
                                dbg(x, y, z);

                return true;
            };
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    for (int k = 0; k <= 9; k++) {
                        if (hs.contains(i) and hs.contains(j) and hs.contains(k) and work(i, j, k)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };

        if (check()) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
/*

*/