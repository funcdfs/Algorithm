/**
 * name: 第k个数
 * link: https://www.acwing.com/problem/content/788/
 * time: 2024/5/16 18:05:55 https://github.com/funcdfs
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
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    sort(a.begin(), a.end());
    cout  << a[k - 1];
    
    return 0;
}
/*

*/