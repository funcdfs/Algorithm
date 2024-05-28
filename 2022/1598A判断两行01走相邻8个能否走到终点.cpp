// URL: https://codeforces.com/contest/1598/problem/A
// NAME: A. Computer Game, Codeforces - Educational Codeforces Round 115 (Rated
// for Div. 2) LIMIT: 256 MB, 2000 ms DATE: 2022-08-09 23:23:28

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

bool canReach(string& a, string& b) {
    int n = a.size();
    vector<bool> fa(n, false);
    vector<bool> fb(n, false);

    if (a[0] == '0') fa[0] = true;
   	if (fa[0] && b[0] == '0') fb[0] = true; 
   	
    for (int i = 1; i < n; i++) {
        if (a[i] == '0') {
            if (fb[i] == true || (i && fa[i - 1] == true) ||
                (i && fb[i - 1] == true)) {
                fa[i] = true;
            }
        }
        if (b[i] == '0') {
            if (fa[i] == true || (i && fa[i - 1] == true) ||
                (i && fb[i - 1] == true)) {
                fb[i] = true;
            }
        }
    }

    return fb[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        string a;
        string b;
        cin >> a >> b;

        if (canReach(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*

1598A判断两行01走相邻8个能否走到终点

*/