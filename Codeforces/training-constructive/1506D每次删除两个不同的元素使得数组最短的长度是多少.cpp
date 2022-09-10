// LINK: https://codeforces.com/contest/1506/problem/D
// NAME: D. Epic Transformation, Codeforces - Codeforces Round #710 (Div. 3)
// DATE: 2022-09-10 16:54:23, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int tt = 0;
    cin >> tt;

    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int, int> hs;
        for (int j = 0; j < n; j++) {
            hs[a[j]]++;
        }

        int maxFreq = 0;
        for (auto& [k, v] : hs) {
            maxFreq = max(maxFreq, v);
        }
        if (maxFreq >= (n % 2 ? n / 2 + 1 : n / 2)) {
            debug("Hi"); 
            int ans = n - 2 * (n - maxFreq);
            cout << ans << '\n';
        } else {
            int ans = n % 2;
            cout << ans << '\n';
        }
    }

    return 0;
}

/*

1506D每次删除两个不同的元素使得数组最短的长度是多少

限制 o(n)

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220910171535.png)

*/