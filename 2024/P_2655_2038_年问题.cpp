/**
 * name: P2655 2038年问题
 * link: https://www.luogu.com.cn/problem/P2655
 * time: 2024/5/16 18:00:27 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */



auto solve(int _case) -> void {
    dbg(_case);
    
    vector<int> a(7, 0);
    for (int i = 0; i < n; i++) {
        cin >>a[i];
    }

    
    
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*

*/