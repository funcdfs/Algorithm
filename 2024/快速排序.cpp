/**
 * name: 快速排序
 * link: https://www.acwing.com/problem/content/787/
 * time: 2024/5/16 18:04:58 https://github.com/funcdfs
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

    sort(a.begin(), a.end());

    for (int i = 0; i < (int)a.size() ; i++) {
        cout << format("{0} ", a[i]);
    }
    
    return 0;
}
/*

*/