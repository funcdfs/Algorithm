/**
 * name:  Apples Prologue / 苹果和虫子
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5709
 * time: 2024/5/17 11:38:57 https://github.com/funcdfs
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
    
    int m, t, s;
    cin >> m >> t >> s;

    int cnt = s / t;
    int mod = s  % t;
    int ans = m - cnt;
    if (mod ) {
        ans -= 1;
    }
    cout << format("{0}\n", ans);
    
    return 0;
}
/*

*/