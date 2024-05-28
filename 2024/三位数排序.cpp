/**
 * name:  三位数排序
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5715
 * time: 2024/5/17 12:23:02 https://github.com/funcdfs
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a);

    for (int i = 0; i < (int)a.size(); i++) {
        cout << format("{0} ", a[i]);
    }
    
    return 0;
}
/*

*/