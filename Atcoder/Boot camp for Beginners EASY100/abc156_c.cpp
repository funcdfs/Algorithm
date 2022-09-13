// LINK: https://atcoder.jp/contests/abc156/tasks/abc156_c?lang=en
// NAME: C - Rally, AtCoder - AtCoder Beginner Contest 156
// DATE: 2022.09.13 22:20:48, LIMIT: 1024 MB, 2000 ms

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

    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int64_t ans = numeric_limits<int64_t>::max();

    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end());
    for (int i = l; i <= r; i++) {
        int64_t t = 0;
        for (auto& x : a) {
            t += (i - x) * (i - x);
        }
        ans = min(t, ans);
    }

    cout << ans << '\n';

    return 0;
}

/*

找出n个人的最少力气之和

*/