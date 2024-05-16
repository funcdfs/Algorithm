/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1620/problem/A
 * created: 5/12/2024, 10:45:18 PM	
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
        string s;
        cin >> s;
        auto judge = [&]() ->bool {
            int cnt = count_if(s.begin(), s.end(), [&](auto& x){ return x == 'N';});
            if (cnt == 1) {
                return false;
            }
            return true;
        };
        if (judge()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
/*

*/