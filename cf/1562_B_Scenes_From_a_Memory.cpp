/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 17:11:19
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    vector<bool> isPrime(100, true);
    for (int i = 2; i < 100; i++) {
        for (int j = 2 * i; j < 100; j += i) {
            isPrime[j] = false;
        }
    }
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int k  = 0; 
        cin >> k;
        string s = string(k, ' ');
        cin >> s;
        // delete digit to make the remain number is not prime 
        bool ok = false;
        for (int i = 0; i < k; i++) {
            if (isPrime[s[i] - '0'] == false) {
                cout << 1 << '\n';
                cout << s[i] << '\n';
                ok = true;
                break;
            }
        }
        // single number: 1 4 6 8 9
        if (ok) continue;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int x = (s[i] - '0') * 10 + s[j] - '0';
                if (isPrime[x] == false) {
                    cout << 2 << '\n';
                    cout << s[i] << s[j] << '\n';
                    ok = true;
                    break;
                }
            }
        }
        // two same dight: 22 33 55 77 is divisible by 11
        // the three dight: 237, 273-> 27 || 537, 573-> 57=2*19, so all left number can be two digit
        if (ok == false) {
            assert(false);
        }
    }
    
    return 0;
}
/*

*/