// LINK: https://codeforces.com/contest/1547/problem/D
// NAME: D. Co-growing Sequence, Codeforces - Codeforces Round #731 (Div. 3)
// DATE: 2022.09.14 23:57:51, LIMIT: 512 MB, 2000 ms

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ans(n);
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            cur |= a[i - 1];
            ans[i] = cur & ~a[i];
        }
        for (int i : ans) cout << i << " ";
        cout << '\n';
    }
}
/*

1547D构建b数组二进制或之后前后项不变


TODO: 二进制

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220915204651.png)
*/