#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    vector<int> a(x, y);
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] += 1;
    }
    cout << x << y;

    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " \n"[i == (int)a.size() - 1];
    }

    return 0;
}
/*

*/