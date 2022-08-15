#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (cnt * t <= a[i]) {
            cnt++;
        } else {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*



*/