/**
 * problem: https://vjudge.net/problem/AtCoder-abc350_a#author=GPT_zh
 * created: https://github.com/funcdfs 5/15/2024, 6:20:23 PM 
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
    
    string s;
    cin >> s;
    string tmp = "ABC350";
    bool ok = true;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i <= 2) {
            if (s[i] != tmp[i]) {
                ok = false;
            }
        }
        if (i > 2) {
            if (!(s[i] >= '0' and s[i] <= '9')) {
                ok = false;
            } else {
                if (s[i] > tmp[i]) {
                    ok = false;
                }
            }
        }
    }
    
    if (ok == false){
        cout << format("No\n");
    } else {
        cout << format("Yes\n");
    }
    return 0;
}
/*

*/