/**
 * author: https://github.com/funcdfs
 * created: 2024-04-24 13:07:10
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
    vector<string> s(n);
    unordered_map<string, int> hs;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (hs.find(s[i]) == hs.end()) {
            cout << s[i] << endl;
            hs[s[i]] += 1;
        } else {
            continue;
        }
    }
    
    return 0;
}
/*

*/