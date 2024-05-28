/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 12:02:34
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

    string s = "1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
    unordered_map<char, int> hs;
    for (int i = 0; i < (int)s.size(); i++) {
        hs[char(s[i])] = i;
    }
    string input = "";
    while (getline(cin, input)) {
        string ans = input;
        for (int i = 0; i < (int)input.size(); i++) {
            if (input[i] == ' ') continue;
            ans[i] = s[hs[input[i]] - 1];
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/