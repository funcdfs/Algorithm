// LINK: https://codeforces.com/contest/1400/problem/C
// NAME: C. Binary String Reconstruction, Codeforces - Educational Codeforces
// Round 94 (Rated for Div. 2) DATE: 2022.09.14 09:55:36, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        string s = "";
        cin >> s;
        int x = 0;
        cin >> x;
        int n = (int)s.size();

        string w = string(n, '1');
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i >= x) {
                    w[i - x] = '0';
                }
                if (i + x < n) {
                    w[i + x] = '0';
                }
            }
        }
        dbg(w);

        for (int i = 0; i < n; i++) {
            // 判断每一个 1 的左右两侧会不会存在 1 
            if (s[i] == '0') continue;
            bool okLeft = false, okRight = false;
            if (i >= x && w[i - x] == '1') okLeft = true;
            if (i + x < n && w[i + x] == '1') okRight = true;
            
            if (okLeft == false && okRight == false) {
                w = "-1";
                break;
            }
        }

        cout << w << '\n';
    }

    return 0;
}

/*

1400C根据s和x构造w

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914105907.png)

*/