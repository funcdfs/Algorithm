/**
 * author: https://github.com/funcdfs
 * created: 2024-04-29 12:41:26
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
    
    cout << "YES\n";
    
    cout << "NO\n";
    
    cout << "No\n";
    
    cout << fixed << setprecision(20);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> " \n"[i == n - 1];
    }
    
    
    
    return 0;
}
/*

*/